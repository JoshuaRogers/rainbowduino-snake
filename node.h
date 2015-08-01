#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
  public:
    Node(T value);
    T get_value();
    Node<T>* next;

  private:
    T m_value;
};

template <typename T>
Node<T>::Node(T value) : next(0) {
  m_value = value;
}

template <typename T>
T Node<T>::get_value() {
  return m_value;
}


#endif
