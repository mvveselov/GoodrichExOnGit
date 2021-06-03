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
    std::cout << "##############Checking Iterator###############" << std::endl;
    std::cout << "NodeList l: " << l;
    std::cout << "NodeList l1: " << l1;
    NodeList<int>::Iterator it = l1.end(); /// разобраться как работает такой пособ
    it = l.end();
    //std::cout << "l1.begin() is "  << *it << std::endl;
    it = l1.end();
    l.inserterr(it, 40); // должна говорить Error не тот объект
    std::cout << "It is mistaken to expect to see 40 in l due to it belongs to l1" << std::endl;
    std::cout << "NodeList l: " << l;
    std::cout << "NodeList l1: " << l1;
    std::cout << "Insert 40 to l oject" << std::endl;
    l.insert(it, 40);
    std::cout << "NodeList l: " << l;
    std::cout << "NodeList l1: " << l1;
	return 0;
}
