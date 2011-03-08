#include <boost/program_options.hpp>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/regex.hpp>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
namespace io = boost::iostreams;

#include "SocketExample.hpp"

namespace po = boost::program_options;
namespace io = boost::iostreams;

void test_socket(int port) {
	SocketExample sl(port);
	sl.start(); // kick the thread spinning
	sl.join(); // wait for thread to finish
}

int main(int argc, char* argv[]) {

	// Declare the supported options.
	po::options_description cmd_cfg("Command line configuration");
	cmd_cfg.add_options()("help,h", "Show this message.")("port,p", po::value<
			int>(), "Set listening port.")("config,c",
			po::value<std::string>()->default_value("bgpd-ng.cfg"),
			"Application configuration file.");

	po::options_description tests("Handles for running unit tests");
	tests.add_options()("test-socket",
			"Run example socket server (ctrl-c to exit)")("print-routes",
			"Print all default routes from configuration file stdout.");

	po::options_description routes("Default routes");

	// Option groups.
	po::options_description all_cmd("All command line options");
	all_cmd.add(cmd_cfg).add(tests);

	po::options_description all_cfg("All configuration file options");
	all_cfg.add(cmd_cfg).add(routes);

	// Parse command line.
	po::variables_map vm;
	try {
		po::store(po::parse_command_line(argc, argv, all_cmd), vm);
		po::notify(vm);
	} catch (std::exception e) {
		std::cout << "Wrong command line argument. See --help for more.\n";
		return 1;
	}

	// Parse configuration file.
	io::stream<io::file_source> icmd_cfg(
			vm["config"].as<std::string> ().c_str());
	po::parsed_options cfg_opts =
			po::parse_config_file(icmd_cfg, all_cfg, true);
	po::store(cfg_opts, vm);
	po::notify(vm);

	// Handle options.
	if (vm.count("help")) {
		std::cout << all_cmd << "\n";
		return 1;
	}
	if (vm.count("test-socket")) {
		if (vm.count("port")) {
			test_socket(vm["port"].as<int> ());
		} else {
			std::cout << "Listening port was not set.\n";
		}
	}
	if (vm.count("print-routes")) {
		std::vector<std::string>::iterator it;
		boost::regex expression("^routes.(.*)");

		std::vector<std::string> to_pass_further = po::collect_unrecognized(
				cfg_opts.options, po::include_positional); // or include_positional

		std::cout << "Routes from configuration file:\n";

		for (it = to_pass_further.begin(); it < to_pass_further.end(); it++) {
			boost::cmatch match;

			// if this line is route.someting, next one is the route specification
			if (boost::regex_search(it->c_str(), match, expression)) {
				std::cout << "Route " << match[1] << ": ";
				it++;
				std::cout << it->c_str() << "\n";
			}
		}
	}

}
