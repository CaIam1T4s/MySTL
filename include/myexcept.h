#ifndef MYEXCEPT_H
#define MYEXCEPT_H

#include <cstddef>
#include <stdexcept>

namespace mystl {

template <size_t N>
constexpr auto CheckOutOfRange(size_t idx) {
	if constexpr (N == 0 || (idx + 1 >= N)) {
		throw std::out_of_range("index out of range");
	} else {
		return false;
	}
	return true;
}

auto CheckOutOfRange(size_t size, size_t idx) {
	if (size == 0 || (idx + 1 >= size)) {
		throw std::out_of_range("index out of range");
	} else {
		return false;
	}
	return true;
}

}	// namespace mystl

#endif	// MYEXCEPT_H
