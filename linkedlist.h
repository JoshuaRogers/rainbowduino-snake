#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "node.h"

template <typename T>
class LinkedList
{
public:
    LinkedList();
    void add(T value);
    Node<T>* get_head();
    
private:
    Node<T>* m_node_first;
    Node<T>* m_node_last;
};

template <typename T>
LinkedList<T>::LinkedList() : m_node_first(0), m_node_last(0)
{
}

template <typename T>
void LinkedList<T>::add(T value)
{
    Node<T>* node = new Node<T>(value);
    if (m_node_first == 0) {
        m_node_first = m_node_last = node;
    } else {
        m_node_last->next = node;
        m_node_last = node;
    }
}

template <typename T>
Node<T>* LinkedList<T>::get_head()
{
    return m_node_first;
}

#endif
