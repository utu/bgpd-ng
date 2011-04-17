#ifndef PREFIX_HPP_
#define PREFIX_HPP_

class Prefix {
public:

	bool isIPv6;
	__uint8_t length; // in bits, zero for all
	__uint32_t prefix[4]; // length(ipv6) == 4*32 == 128 bits

	const bool isExact() {
		if (isIPv6 && (length == 128)) {
			return true;
		} else if (!isIPv6 && (length == 32)) {
			return true;
		}
		return false;
	}

	const __uint8_t countMatchingBits(const Prefix &route) {
		// TODO: stub
		return 18;
	}

	const bool operator==(const Prefix comp) {
		if (comp.length != length) {
			return false;
		}
		if (comp.prefix[0] != prefix[0]) {
			return false;
		} else if (comp.isIPv6 != isIPv6) {
			return false;
		} else if (!comp.isIPv6) {
			return true;
		}
		for (int i = 1; i < 4; i++) {
			if (comp.prefix[i] != prefix[i]) {
				return false;
			}
		}
		return true;
	}
};

#endif
