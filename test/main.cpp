#include <iostream>

#include "myexcept.h"

int main() {
	std::cout << mystl::CheckOutOfRange<2, 2>() << std::endl;
}
