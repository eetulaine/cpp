#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#define BLUE		"\033[0;94m"
#define RED			"\033[0;31m"
#define END	"\033[0m"

class Span {

	private:
		unsigned int maxSize_;
		std::vector<int> storedNumbers_;

	public:
		Span();
		Span(unsigned int N);

		Span(const Span& copy);
		Span &operator=(const Span& other);

		~Span();

		void addNumber(const int& n);
		int shortestSpan();
		int longestSpan();

		template<typename Iterator>
		void addRange(Iterator start, Iterator end) {
			int dist = std::distance(start, end);
			if (storedNumbers_.size() + dist > maxSize_)
				throw SpanFullException();
			storedNumbers_.insert(storedNumbers_.end(), start, end);
			std::cout << "Added a range of " << dist << " values\n";
		}

		class SpanFullException : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return RED "Error: No space left" END;
				}
		};
		class NoSpanException : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return RED "Error: Not enough values to count span" END;
				}
		};
};