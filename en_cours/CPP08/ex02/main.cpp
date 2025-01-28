#include "MutantStack.hpp"
#include <iostream>

int	main(void)
{
	MutantStack<int> mstack;
	std::cout << "SOME STACK TESTS: " << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.pop();
	//Stack for the test
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "ITERATION TEST: " << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	it++;
	it--;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::stack<int> s(mstack);

	MutantStack<int> mstack2(mstack);
	std::cout << "ITERATION TEST COPIED STACK: " << std::endl;
	it = mstack2.begin();
	ite = mstack2.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	mstack.push(2222);
	mstack.push(44444);
	mstack2 = mstack;
	std::cout << "ITERATION TEST COPIED WITH = STACK: " << std::endl;
	it = mstack2.begin();
	ite = mstack2.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	return (0);
}