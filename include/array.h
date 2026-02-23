#ifndef ARRAY_H
#define	ARRAY_H

#include <cstddef>
#include <initializer_list>

#include "iterator.h"

namespace mystl {

template <typename Ty, size_t N>
class ConstArrayIterator {
public:
	using DiffType  = std::ptrdiff_t;
	using ValueType = Ty;
	using Reference = const Ty&;
	using Pointer   = const Ty*;
public:
	ConstArrayIterator();
private:
	Pointer m_ptr;
};	// class ConstArrayIterator


template <typename Ty, size_t N>
class ArrayIterator : public ConstArrayIterator<Ty, N> {
public:
	using ValueType = Ty;
	using DiffType  = std::ptrdiff_t;
	using Reference = Ty&;
	using Pointer   = Ty*;
public:
private:
};


// class declaration
template <typename Ty, size_t N>
class Array {
public:
	using SizeType       = size_t;
	using ValueType      = Ty;
	using Reference      = Ty&;
	using ConstReference = const Ty&;
	using Pointer        = Ty*;
	using ConstPointer   = const Ty*;
	using Iterator       = ArrayIterator<Ty, N>;
	using ConstIterator  = ConstArrayIterator<Ty, N>;
public:
	Array();
	Array(const Array<Ty, N>& other);
	Array(Array<Ty, N>&& other) noexcept;
	Array(std::initializer_list<Ty>);
	Array(Ty (&arr)[N]);
	~Array();
public:
	auto At(size_t index) -> Reference;
	auto At(size_t index) const -> ConstReference;
	auto Back() -> Reference;
	auto Back() const -> ConstReference;
	auto Begin() -> Iterator;
	[[nodiscard]] auto Empty() const -> bool;
	void Swap(Array<Ty, N>& other);
private:
	auto CheckSafe(size_t index) -> bool;
private:
	Ty m_array[N];
};	// class Array


// functions
// Get a value by passing index and a Array(rvalue ver. is disabled)
template <size_t Index, typename Ty, size_t Size>
auto Get(Array<Ty, Size>& arr) -> Ty& { return arr.At(Size); }

template <size_t Index, typename Ty, size_t Size>
auto Get(const Array<Ty, Size>& arr) -> const Ty& { return arr.At(Size); }

template <typename Ty, size_t N>
void Swap(Array<Ty, N>& lhs, Array<Ty, N>& rhs) { lhs.Swap(rhs); }

template <typename Ty, size_t N>
auto ToArray(Ty (&arr)[N]) -> Array<Ty, N> {
	return Array(arr);
}

template <typename Ty, size_t N>
auto ToArray(Ty (&&array)[N]) -> Array<Ty, N> {
	return Array(move(arr));
}

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

}	// namespace mystl

#endif	// ARRAY_H
