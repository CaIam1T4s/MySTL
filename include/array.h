#ifndef ARRAY_H
#define	ARRAY_H

#include <cstddef>
#include <initializer_list>

#include "iterator.h"
#include "myexcept.h"
#include "utility.h"

namespace mystl {

template <typename Ty, size_t N>
class ConstArrayiterator {
public:
	using diff_type  = std::ptrdiff_t;
	using value_type = Ty;
	using reference  = const Ty&;
	using pointer    = const Ty*;
public:
	ConstArrayiterator();

	auto operator*() const -> reference {
		return *m_ptr;
	}

	auto operator->() const -> pointer {
		return m_ptr;
	}

	auto operator++() -> ConstArrayiterator& {
		++m_ptr;
		return *this;
	}

	auto operator++(int) -> ConstArrayiterator {
		auto tmp = *this;
		++m_ptr;
		return tmp;
	}

	auto operator--() -> ConstArrayiterator {
		--m_ptr;
		return *this;
	}

	auto operator--(int) -> ConstArrayiterator {
		auto tmp = *this;
		--m_ptr;
		return tmp;
	}
private:
	pointer m_ptr;
};	// class ConstArrayiterator


template <typename Ty, size_t N>
class Arrayiterator : public ConstArrayiterator<Ty, N> {
private:
	using MyBase     = ConstArrayiterator<Ty, N>;
public:
	using value_type = Ty;
	using diff_type  = std::ptrdiff_t;
	using reference  = Ty&;
	using pointer    = Ty*;
public:
	auto operator*() -> reference {
		return const_cast<reference>(MyBase::operator*());
	}

	auto operator->() -> pointer {
		return const_cast<pointer>(MyBase::operator->());
	}

private:
};


template <typename Ty, size_t N>
class Array {
public:
	using SizeType        = size_t;
	using value_type      = Ty;
	using reference       = Ty&;
	using const_reference = const Ty&;
	using pointer         = Ty*;
	using const_pointer   = const Ty*;
	using iterator        = Arrayiterator<Ty, N>;
	using const_iterator  = ConstArrayiterator<Ty, N>;
public:
	Array();
	Array(const Array<Ty, N>& rhs);
	auto operator=(const Array<Ty, N>& rhs) -> Array&;
	Array(Array<Ty, N>&& rhs) noexcept;
	auto operator=(Array<Ty, N>&& rhs) noexcept -> Array&;
	Array(std::initializer_list<Ty>) {

	}
	~Array();

	Array(Ty (&arr)[N]);
public:
	auto At(size_t idx) -> reference {
		CheckOutOfRange(N, idx);
		return m_arr[idx];
	}

	constexpr auto At(size_t idx) const -> const_reference {
		CheckOutOfRange<N, idx>();
		return m_arr[idx];
	}

	auto Back() -> reference;
	auto Back() const -> const_reference;
	auto Begin() -> iterator;
	auto Cbegin() const -> const_iterator;
	auto End() -> iterator;
	auto Cend() const -> const_iterator;
	auto Data() -> Ty*;
	auto Data() const -> const Ty*;
	[[nodiscard]] auto Empty() const -> bool;
	void Fill(Ty& val);
	auto Front() -> reference;
	auto Front() const -> const_reference;
	[[nodiscard]] auto MaxSize() const -> SizeType { return N; }

	[[nodiscard]] auto Size() const -> SizeType { return N; }

	void Swap(Array<Ty, N>& rhs) {
		
	}

	auto operator[](size_t idx) -> Ty&;
private:
	Ty m_arr[N];
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
auto ToArray(Ty (&&arr)[N]) -> Array<Ty, N> {
	return Array(Move(arr));
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
