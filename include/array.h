#ifndef ARRAY_H
#define	ARRAY_H

#include <initializer_list>

// tstl = tiny standard template library
namespace tstl {

// class declaration
template <typename Ty, size_t N>
class Array {
public:
	using size_type = size_t;
	using value_type = Ty;
	using reference = Ty&;
	using pointer = Ty*;
	using const_pointer = const Ty*;
public:
	Array();
	Array(std::initializer_list<Ty>);
public:
	auto At(size_t index) -> Ty&;
	auto At(size_t index) const -> const Ty&;
	auto Back() -> Ty&;
	auto Back() const -> const Ty&;
	void Swap(Array<Ty, N>& other);
private:
	auto CheckSafe(size_t index) -> bool;
private:
	Ty m_array[N];
};	// class Array


// functions
// Get a value by passing index and a Array
template <size_t Index, typename Ty, size_t Size>
auto Get(Array<Ty, Size>& array) -> Ty&;

template <size_t Index, typename Ty, size_t Size>
auto Get(const Array<Ty, Size>& array) -> const Ty&;

template <size_t Index, typename Ty, size_t Size>
auto Get(Array<Ty, Size>& array) -> Ty&&;

template <size_t Index, typename Ty, size_t Size>
auto Get(const Array<Ty, Size>& array) -> const Ty&&;

template <typename Ty, size_t N>
void Swap(Array<Ty, N>& lhs, Array<Ty, N>& rhs);

template <typename Ty, size_t N>
auto ToArray(Ty (&array)[N]) -> Array<Ty, N>;

template <typename Ty, size_t N>
auto ToArray(Ty (&&array)[N]) -> Array<Ty, N>;

// operators
template <typename Ty, size_t N>
auto operator!=(const Array<Ty, N>& lhs, const Array<Ty, N>& rhs) -> bool;

template <typename Ty, size_t N>
auto operator==(const Array<Ty, N>& lhs, const Array<Ty, N>& rhs) -> bool;

template <typename Ty, size_t N>
auto operator<(const Array<Ty, N>& lhs, const Array<Ty, N>& rhs) -> bool;

template <typename Ty, size_t N>
auto operator<=(const Array<Ty, N>& lhs, const Array<Ty, N>& rhs) -> bool;

template <typename Ty, size_t N>
auto operator>(const Array<Ty, N>& lhs, const Array<Ty, N>& rhs) -> bool;

template <typename Ty, size_t N>
auto operator>=(const Array<Ty, N>& lhs, const Array<Ty, N>& rhs) -> bool;

}	// namespace tstl

#endif
