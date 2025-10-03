#include "Span.hpp"

Span::Span() : maxSize_(0) {
	std::cout << "Default Span created\n";
}

Span::Span(unsigned int N) : maxSize_(N) {
	std::cout << "Span created able to store up to " << maxSize_ << " integers\n";
}

Span::Span(const Span& copy) : maxSize_(copy.maxSize_) {
	std::cout << "Span copy constructor called\n";
}

Span& Span::operator=(const Span& other) {
	std::cout << "Span copy assignment operator called\n";
	if (this != &other) {
		maxSize_ = other.maxSize_;
		storedNumbers_ = other.storedNumbers_;
	}
	return *this;
}

Span::~Span() {
	std::cout << "Span destroyed\n";
}

void Span::addNumber(const int& number) {

	if (storedNumbers_.size() >= maxSize_)
		throw SpanFullException();
	storedNumbers_.push_back(number);
	std::cout << "Added: " << number << "\n";
}

int Span::shortestSpan() {

	if (storedNumbers_.size() < 2)
		throw NoSpanException();

	std::vector<int> sortedCopy = storedNumbers_;
	std::sort(storedNumbers_.begin(), storedNumbers_.end());

	int minDist = __INT_MAX__;
	for (size_t i = 0; i < storedNumbers_.size() - 1; i++) {
		int curDist = storedNumbers_[i + 1] - storedNumbers_[i];
		if (curDist < minDist)
			minDist = curDist;
	}
	return minDist;
}

int Span::longestSpan() {

	if (storedNumbers_.size() < 2)
		throw NoSpanException();
	auto it = std::minmax_element(storedNumbers_.begin(), storedNumbers_.end());
	int maxDist = *it.second - *it.first;
	return maxDist;
}
