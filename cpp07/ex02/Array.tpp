#include "Array.hpp"

template <typename T>
Array<T>::Array() : size_(0), array_(nullptr) {}

template <typename T>
Array<T>::Array(unsigned int n) : size_(n), array_(new T[n]) {}

template <typename T>
Array<T>::Array(const Array& copy) : size_(copy.size_), array_(nullptr) {
	array_ = new T[size_];
	for (size_t i = 0; i < size_; i++) {
		array_[i] = copy.array_[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] array_;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {

	if (this != &other) {
		delete[] array_;
		size_ = other.size();
		if (size_ > 0) {
			array_ = new T[size_];
			for (size_t i = 0; i < size_; i++) {
				array_[i] = other.array_[i];
			}
		} else {
			array_ = nullptr;
		}
	}
	return *this;
}

template <typename T>
size_t Array<T>::size() const {
	return size_;
}

template <typename T>
T& Array<T>::operator[](size_t i) {
	if (i >= size())
		throw std::out_of_range("Array index out of range");
	return array_[i];
}

template <typename T>
const T& Array<T>::operator[](size_t i) const {
	if (i >= size())
		throw std::out_of_range("Array index out of range");
	return array_[i];
}