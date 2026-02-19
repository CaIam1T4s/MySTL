#ifndef ARRAY_H
#define	ARRAY_H

#include <initializer_list>

// tstl = tiny standard template library
namespace tstl {

template <typename Ty, size_t N>
class Array {
public:
	Array();
	Array(std::initializer_list<Ty>);
public:
	auto At() -> Ty&;
private:
	auto CheckSafe(size_t index) -> bool;
private:
	Ty m_array[N];
};	// class Array

}	// namespace tstl

#endif
