#ifndef _NODELIST_H_
#define _NODELIST_H_

//typedef int Elem;
template<typename E>
class NodeList;


template<typename E>
std::ostream& operator<< (std::ostream& os, const NodeList<E>& ls);

template<typename E>
class NodeList
{
private:
    struct Node {
        E elem;
        Node* prev;
        Node* next;
    };
public:
    class Iterator {
        public:
            E& operator*();
            bool operator==(const Iterator& p) const;
            bool operator!=(const Iterator& p) const;
            Iterator& operator++();
            Iterator& operator++(int);
            Iterator& operator--();
            Iterator& operator=(const Iterator& obj);
            friend class NodeList;
            friend std::ostream& operator<< <> (std::ostream& os, const NodeList<E>& ls);
        private:   
            Node* indicator_header_trailer;
           // Node* indicator_trailer;
            Node* v;
            Iterator(Node* indicator, Node* u);
        public:
            ~Iterator() = default;
    };
public:
    NodeList();
    NodeList(const NodeList& obj); //copy constructor
    ~NodeList();
    NodeList& operator=(const NodeList& obj);
    int size() const;
    bool empty() const;
    Iterator begin() const;
    Iterator end() const;
    void insertFront(const E& e);
    void insertBack(const E& e);
    void insert(const Iterator& p, const E& e);
    void inserterr(const Iterator& p, const E& e);
    void eraseFront();
    void eraseBack();
    void erase(const Iterator& p);
private:
    int n;
    Node* header;
    Node* trailer;
};


    template<typename E>
    std::ostream& operator<< (std::ostream& os, const NodeList<E>& ls) {
    for(typename NodeList<E>::Iterator it = ls.begin(); it != ls.end(); ++it)
        os << *it << " ";
    os << std::endl;
    return os;
    }
    
    
    template<typename E>
    int NodeList<E>::size() const {
        return n;
    }
    
    template<typename E>
    bool NodeList<E>::empty() const {
        return (n == 0);
    }
    
    template<typename E>
    typename NodeList<E>::Iterator NodeList<E>::begin() const { // where trailer points to
       // std::cout << "Iterator begin() created\n";
        return Iterator(header, header->next);
    }
    
    template<typename E>
    typename NodeList<E>::Iterator NodeList<E>::end() const {
       // std::cout << "Iterator end() created\n";
        return Iterator(trailer, trailer);
    }
    
    template<typename E>
    void NodeList<E>::insert( const NodeList<E>::Iterator& p, const E& e) {
        
        Node* w = p.v; // second
        Node* u = w->prev; // first
        Node* v = new Node;
        v->elem = e;
        v->next = w; w->prev = v;
        v->prev = u; u->next = v; // v is between first and second
        n++;
    }
    
    
    template<typename E>
    void NodeList<E>::inserterr(const NodeList<E>::Iterator& p, const E& e) {
        if (p.indicator_header_trailer == this->header || p.indicator_header_trailer == this->trailer) {
            Node* w = p.v; // second
            Node* u = w->prev; // first
            Node* v = new Node;
            v->elem = e;
            v->next = w; w->prev = v;
            v->prev = u; u->next = v; // v is between first and second
            n++;
        } 
        
        else std::cout << "Error, wrong object" << std::endl;
        
    }
    
    
    
    template<typename E>
    void NodeList<E>::insertFront(const E& e) {
        insert(begin(), e);
    }
    
    template<typename E>
    void NodeList<E>::insertBack(const E& e) {
        insert(end(), e);
    }
    
    template<typename E>
    NodeList<E>::NodeList() {
        n = 0;
        header = new Node;
        trailer = new Node;
        header->next = trailer;
        trailer->prev = header;
    }
    
    template<typename E>
    NodeList<E>::NodeList(const NodeList<E>& obj)
    :NodeList() {
        for(NodeList<E>::Iterator it = obj.begin(); it != obj.end(); ++it)
            this->insertBack(*it);
    }
    
    template<typename E>
    NodeList<E>::~NodeList() {
        std::cout << "NodeList destructor is called" << std::endl;
        while(header->next != trailer && trailer->prev != header && n == 0)
            eraseBack();
    }
    
    template<typename E>
    NodeList<E>& NodeList<E>::operator=(const NodeList<E>& obj) {
        while(!this->empty())
            this->eraseBack();
        for(typename NodeList<E>::Iterator it = obj.begin(); it != obj.end(); it++) {
            this->insertBack(*it);
        }
        return *this;
    }
    
    template<typename E>
    void NodeList<E>::erase(const Iterator& p) {
    try {
        if (!empty()) {
        Node* v = p.v;
        Node* w = v->next;
        Node* u = v->prev;
        u->next = w; w->prev = u;
        delete v;
        n--;
        } else throw ("erase function: list is empty");
    }
    catch (const char* s) {
            std::cerr << "Error: " << s << std::endl;
        }
    }

    template<typename E>
    void NodeList<E>::eraseFront() {
        erase(begin());
    }
    
    template<typename E>
    void NodeList<E>::eraseBack() {
        erase(--end());
    }
    
    
    ///////////////// iterators////////////////////////////
    
    template<typename E>
    NodeList<E>::Iterator::Iterator(Node* indicator, Node* u) {
        indicator_header_trailer = indicator;
        v = u;
    }
    
    template<typename E>
    E& NodeList<E>::Iterator::operator *() {
        return v->elem;
    }
    
    template<typename E>
    bool NodeList<E>::Iterator::operator ==(const Iterator& p) const {
        return v == p.v;
    }
    
    template<typename E>
    bool NodeList<E>::Iterator::operator !=(const Iterator& p) const {
        return v != p.v;
    }
    
    template<typename E>
    typename NodeList<E>::Iterator& NodeList<E>::Iterator::operator++() {
        v = v->next; return *this;
    }
    
    template<typename E>
    typename NodeList<E>::Iterator& NodeList<E>::Iterator::operator++(int) {
        v = v->next; return *this;
    }
    
    template<typename E>
    typename NodeList<E>::Iterator& NodeList<E>::Iterator::operator--() {
        v = v->prev; return *this;
    }
    
    template<typename E>
    typename NodeList<E>::Iterator& NodeList<E>::Iterator::operator= (const Iterator& obj) {
        this->v = obj.v;
        this->indicator_header_trailer = obj.indicator_header_trailer;
        return *this;
    }

    

#endif // _NODELIST_H_
