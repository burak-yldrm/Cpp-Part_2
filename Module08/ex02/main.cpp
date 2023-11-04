#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int> mstack_assigment;
	mstack_assigment = mstack;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << s.size() << std::endl;


	std::cout << "\n\nLIST EXAMPLE------------------\n\n";

	std::list<int> tempList;
	tempList.push_back(5);
	tempList.push_back(17);
	std::cout << tempList.back() << std::endl;
	tempList.pop_back();
	std::cout << tempList.size() << std::endl;
	tempList.push_back(3);
	tempList.push_back(5);
	tempList.push_back(737);
	tempList.push_back(0);

	std::list<int> tempList2;
	tempList2 = tempList;

	std::list<int>::iterator lstIt = tempList.begin();
	std::list<int>::iterator lstIt2 = tempList.end();

	++lstIt;
	--lstIt;

	while (lstIt != lstIt2)
	{
		std::cout << *lstIt << std::endl;
		++lstIt;
	}
	std::list<int> ss(tempList);

	std::cout << ss.size() << std::endl;
	return 0;
}
