#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try {
		std::vector<int>::iterator result = easyfind(vec, 3);
		std::cout << "Value found at index: " << std::distance(vec.begin(), result) << std::endl;
	} catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::list<int> myList;
	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);
	myList.push_back(40);
	myList.push_back(50);

	try {
		std::list<int>::iterator result = easyfind(myList, 21);
		std::cout << "Value found at index: " << std::distance(myList.begin(), result) << std::endl;
	} catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
