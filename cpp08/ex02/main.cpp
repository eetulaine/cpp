#include "MutantStack.hpp"
#include <list>

int main() {
	{
		std::cout << "\n=== MUTANT STACK ===\n\n";

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << "\n";
		mstack.pop();
		std::cout << "MutanStack size: " << mstack.size() << "\n";
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << "\n";
			++it;
		}

		std::cout << "MutanStack size: " << mstack.size() << "\n";
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n=== LIST COMPARE ===\n\n";

		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << "\n";
		lst.pop_back();
		std::cout << "List size: " << lst.size() << "\n";
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);

		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << "\n";
			++it;
		}
		std::cout << "List size: " << lst.size() << "\n";
		std::list<int> s(lst);
	}
	{
		std::cout << "\n=== MUTANT REVERSE STACK ===\n\n";

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << "\n";
		mstack.pop();
		std::cout << "MutanStack size: " << mstack.size() << "\n";
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);
		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << "\n";
			++it;
		}

		std::cout << "MutanStack size: " << mstack.size() << "\n";
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n=== LIST REVERSE COMPARE ===\n\n";

		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << "\n";
		lst.pop_back();
		std::cout << "List size: " << lst.size() << "\n";
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);

		lst.push_back(0);
		std::list<int>::reverse_iterator it = lst.rbegin();
		std::list<int>::reverse_iterator ite = lst.rend();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << "\n";
			++it;
		}
		std::cout << "List size: " << lst.size() << "\n";
		std::list<int> s(lst);
	}
	{
		std::cout << "\n=== CONST STACK ===\n\n";
		MutantStack<int> mstack;
		
		for (int i = 0; i < 10; i++) {
			mstack.push(i);
		}
		MutantStack<int> const cstack(mstack);
		MutantStack<int>::const_iterator it = cstack.begin();
		while (it != cstack.end())
		{
			std::cout << *it << "\n";
			++it;
		}
	}
	{
		std::cout << "\n=== CONST REV STACK ===\n\n";
		MutantStack<int> mstack;
		
		for (int i = 0; i < 10; i++) {
			mstack.push(i);
		}
		MutantStack<int> const cstack(mstack);
		MutantStack<int>::const_reverse_iterator it = cstack.rbegin();
		while (it != cstack.rend())
		{
			std::cout << *it << "\n";
			++it;
		}
	}

	return 0;
}