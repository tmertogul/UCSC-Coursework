// Tim Mertogul
// tmertogu@ucsc.edu
// Michael Lowe
// mimlowe@ucsc.edu
// CMPS109
// Spring 2015
// ASG 3

// $Id: listmap.tcc,v 1.7 2015-04-28 19:22:02-07 - - $

#include "listmap.h"
#include "trace.h"
int ms = 0;

//
// Operations on listmap::node.
//

//
// listmap::node::node (link*, link*, const value_type&)
//
template <typename Key, typename Value, class Less>
listmap<Key,Value,Less>::node::node (node* next, node* prev,
                                     const value_type& value):
    link (next, prev), value (value) {
}
 
//
// Operations on listmap.
//

//
// listmap::~listmap()
//
template <typename Key, typename Value, class Less>
listmap<Key,Value,Less>::~listmap() {
    while (anchor() != anchor_.next) erase(anchor_.next);
    TRACE ('l', (void*) this);
}

//
// iterator listmap::insert (const value_type&)
//
template <typename Key, typename Value, class Less>
typename listmap<Key,Value,Less>::iterator
listmap<Key,Value,Less>::insert (const value_type& pair) {
    TRACE ('l', &pair << "->" << pair); ms++;
    iterator itor;
    Less less;
    for(itor = begin(); itor != end() and less(itor->first, pair.first); ++itor);
    if (itor != end() and not less(pair.first, itor->first)) { 
        itor->second = pair.second;
        return itor;
    }
    node* n = new node(itor.where, itor.where->prev, pair);
    itor.where->prev->next = n;
    itor.where->prev = n;
    return iterator(n);
}

//
// listmap::find(const key_type&)
//

template <typename Key, typename Value, class Less>
typename listmap<Key,Value,Less>::iterator
listmap<Key,Value,Less>::find (const key_type& that) {
    TRACE ('l', that);
    iterator itor;
    Less less;
    for(itor = begin(); itor != end() and less(itor->first, that); ++itor);
    if (itor != end() and not less(that, itor->first)) {
        cout << *itor << endl;
        return itor;
    } else { cerr << that << ": key not found" << endl; }
    return end();
}

template <typename Key, typename Value, class Less>
void listmap<Key,Value,Less>::printVal (const mapped_type& that) {
    for(iterator itor = begin(); itor != end(); ++itor) {
        if (that == itor->second) cout << *itor << endl;
    } 
}

template <typename Key, typename Value, class Less>
void listmap<Key,Value,Less>::print () {
    for(iterator itor = begin(); itor != end(); ++itor) cout << *itor << endl;
}

//
template <typename Key, typename Value, class Less>
void listmap<Key,Value,Less>::rm (const key_type& that) {
    TRACE ('l', that);
    iterator itor = find(that);
    Less less;
    if (itor != end() and not less(that, itor->first)) erase(itor);
    else cerr << that << ": key not found" << endl;
}

//
// iterator listmap::erase (iterator position)
//
template <typename Key, typename Value, class Less>
typename listmap<Key,Value,Less>::iterator
listmap<Key,Value,Less>::erase (iterator position) {
    position.where->next->prev = position.where->prev;
    position.where->prev->next = position.where->next;
    iterator result = position.where->next;
    delete position.where; ms--;
    return result;
}

//
// Operations on listmap::iterator.
//

//
// listmap::value_type& listmap::iterator::operator*()
//
template <typename Key, typename Value, class Less>
typename listmap<Key,Value,Less>::value_type&
listmap<Key,Value,Less>::iterator::operator*() {
   TRACE ('l', where);
   return where->value;
}

//
// listmap::value_type* listmap::iterator::operator->()
//
template <typename Key, typename Value, class Less>
typename listmap<Key,Value,Less>::value_type*
listmap<Key,Value,Less>::iterator::operator->() {
   TRACE ('l', where);
   return &(where->value);
}

//
// listmap::iterator& listmap::iterator::operator++()
//
template <typename Key, typename Value, class Less>
typename listmap<Key,Value,Less>::iterator&
listmap<Key,Value,Less>::iterator::operator++() {
   TRACE ('l', where);
   where = where->next;
   return *this;
}

//
// listmap::iterator& listmap::iterator::operator--()
//
template <typename Key, typename Value, class Less>
typename listmap<Key,Value,Less>::iterator&
listmap<Key,Value,Less>::iterator::operator--() {
   TRACE ('l', where);
   where = where->prev;
   return *this;
}

//
// bool listmap::iterator::operator== (const iterator&)
//
template <typename Key, typename Value, class Less>
inline bool listmap<Key,Value,Less>::iterator::operator==
            (const iterator& that) const {
   return this->where == that.where;
}

//
// bool listmap::iterator::operator!= (const iterator&)
//
template <typename Key, typename Value, class Less>
inline bool listmap<Key,Value,Less>::iterator::operator!=
            (const iterator& that) const {
   return this->where != that.where;
}

