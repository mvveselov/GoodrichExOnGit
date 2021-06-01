#ifndef _NODESEQUENCE_H_
#define _NODESEQUENCE_H_


template <class E>
class NodeSequence: public NodeList<E>
{
public:
    typename NodeList<E>::Iterator atRank(int i) const;
    int indexOf(const typename NodeList<E>::Iterator& p) const;
};


template <class E>
typename NodeList<E>::Iterator NodeSequence<E>::atRank(int i) const {
    if(i < this->size() - i) {
    typename NodeList<E>::Iterator p = this->begin();
    for (int j = 0; j < i; j++) p++;
    return p;
    } else {
        typename NodeList<E>::Iterator p = this->end();
        for (int j = this->size() - 1; j >= i; j--) --p;
        return p;
    }
    
}
//
template <class E>
int NodeSequence<E>::indexOf(const typename NodeList<E>::Iterator& p) const {
    int i = 0;
    for (typename NodeList<E>::Iterator it = this->begin(); it != p; it++ ) i++;
    return i;
}


#endif // _NODESEQUENCE_H_
