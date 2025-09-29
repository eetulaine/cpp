#pragma once
#include <iostream>
#include <cstddef>
#include <exception>

template <typename T>
class Array {

	private:
		size_t	size_;
		T*		array_;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array &operator=(const Array& other);
		~Array();

		T& operator[](size_t  i);
		const T& operator[](size_t i) const;

		size_t size() const;
};