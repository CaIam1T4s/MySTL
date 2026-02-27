#include <iostream>
#include <stdexcept>

class RangeIterator {
public:
	using size_type = size_t;
	using value_type = int;
	using reference = const int&;
	using pointer = const int*;
public:
	RangeIterator() : m_ptr() {}
	RangeIterator(int* beg, size_t off) : m_ptr(beg + off) {}

	auto operator!=(const RangeIterator& other) -> bool {
		return m_ptr != other.m_ptr;
	}

	auto operator*() -> reference {
		return *m_ptr;
	}

	auto operator->() -> pointer {
		return m_ptr;
	}

	auto operator++() -> RangeIterator {
		++m_ptr;
		return *this;
	}
private:
	int *m_ptr;
};

class Range {
public:
	using iterator = RangeIterator;
	using reference = int&;
public:
	Range(size_t size) : m_size(size), m_arr(new int[size]) {}

	~Range() {
		delete[] m_arr;
	}
public:
	auto begin() -> iterator {
		return iterator(m_arr, 0);
	}

	auto end() -> iterator {
		return iterator(m_arr, m_size);
	}
	
	auto size() -> size_t {
		return m_size;
	}

	auto operator[](size_t idx) -> reference {
		if (idx >= m_size) {
			throw std::out_of_range("out of range");
		} else {
			return m_arr[idx];
		}
	}
private:
	size_t m_size;
	int* m_arr;
};

int main() {
	Range range = Range(5);
	for (int i = 0; i != range.size(); ++i) {
		range[i] = i * 10;
	}	
	
	for (auto& e : range) {
		std::cout << e << '\n';
	}
}
