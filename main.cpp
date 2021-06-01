#include <iostream>
#include "NodeList.h"




int main()
{
	NodeList<int>l{};
    l.insertBack (10);
    l.insertBack (20);
    l.insertBack(30);
    std::cout << "NodeList l: " << l;
    NodeList<int>l1 {l};
    std::cout << "NodeList l1: " << l1;
    l.eraseBack();
    std::cout << "NodeList l: " << l;
    std::cout << "NodeList l1: " << l1;
    std::cout << "Assignment: " << std::endl;
    l = l1;
    std::cout << "NodeList l: " << l;
    std::cout << "NodeList l1: " << l1;
    l.eraseBack();
    std::cout << "NodeList l: " << l;
    std::cout << "NodeList l1: " << l1;
    std::cout << "Thank you, Goodbye!" << std::endl;
	return 0;
}
