#ifndef TREE_H 
#define TREE_H

namespace LZ {

template <typename U> class Iterator;
template <typename T> class List;

template <typename U>
class Node {

    friend class Iterator<U>;
    friend class List<U>;

  private:

    Node(Node* next) :
      d_next(next) {}

    Node* next() { return d_next; }

    Node* d_next;
};

template <typename U>
class Iterator {

  public:
    Iterator(Node<U>* node = 0) :
      d_node(node) {}

    Node<U>& operator*()
    {
	return *d_node;
    }

    Node<U>* operator->()
    {
	return d_node;
    }

  private:
    Node<U>* d_node;
};

template <typename T>
class List {

  public:

    List() :
      d_front(nullptr), d_end(nullptr) {}

    Iterator<T> begin()
    {
	return Iterator<T>(d_front);
    }

    Iterator<T> end()
    {
	return Iterator<T>(d_end + 1);
    }

    void push_front(const T& val)
    {
    }

    void pop_front(const T& val)
    {
    }

    void push_back(const T& val)
    {
    }

    void pop_back(const T& val)
    {
    }

  private:

    Node<U> *d_front;
    Node<U> *d_end;


};

} // close namespace

#endif

