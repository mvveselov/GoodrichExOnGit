#include <iostream>
#include "NodeList.h"
#include "NodeSequence.h"




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
    std::cout << "##############NODESEQUENCE CLASS###############" << std::endl;
    NodeSequence<double>ns {};
    ns.insertBack(10.1);
    ns.insertBack(10.2);
    ns.insertBack(10.3);
    ns.insertBack(10.4);
    std::cout << ns << std::endl;
    std::cout << "atRank()" << std::endl;
    std::cout << *ns.atRank(2) << std::endl;
    std::cout << "indexOf()" << std::endl;
    std::cout << ns.indexOf(ns.begin()) << std::endl;
    

	return 0;
}
