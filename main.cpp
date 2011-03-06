#include <boost/program_options.hpp>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/stream.hpp>
#include <iostream>
#include <string>
namespace io = boost::iostreams;

#include "SocketExample.hpp"

namespace po = boost::program_options;
namespace io = boost::iostreams;

int main(int argc, char* argv[]) {

	// Declare the supported options.
	po::options_description general("Command line configuration");
	general.add_options()("help,h", "Show this message.")("port,p", po::value<
			int>(), "Set listening port.")("config,c",
			po::value<std::string>()->default_value("bgpd-ng.cfg"),
			"Application configuration file.");

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, general), vm);
	po::notify(vm);

	// Parse configuration file.
	io::stream<io::file_source> icfg(vm["config"].as<std::string> ().c_str());
	po::store(po::parse_config_file(icfg, general), vm);
	po::notify(vm);

	// Handle options.
	if (vm.count("help")) {
		std::cout << general << "\n";
		return 1;
	}
	if (vm.count("config")) {

	}

	if (vm.count("port")) {
		std::clog << "Listening port was set to " << vm["port"].as<int> ()
				<< ".\n";
		SocketExample sl(vm["port"].as<int> ());
		sl.start(); // kick the thread spinning
		sl.join(); // wait for thread to finish
	} else {
		std::cout << "Listening port was not set.\n";
	}

}
