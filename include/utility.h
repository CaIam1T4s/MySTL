#ifndef UTILITY_H
#define UTILITY_H

namespace mystl {

template <typename Ty>
auto Move(Ty&& item) -> Ty&& {
	Ty tmp;
	return tmp;
}	// namespace mystl

#endif	// UTILITY_H
