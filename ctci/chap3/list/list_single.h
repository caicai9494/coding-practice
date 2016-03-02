#ifndef LIST_SINGLE_H 
#define LIST_SINGLE_H 

#include <cassert>

namespace LZ {

template <typename U> class Iterator;
template <typename T> class List;

template <typename U>
class Node {

    friend class Iterator<U>;
    friend class List<U>;

  private:

    Node(const U& data, Node *next) :
      d_data(data), d_next(next) {}

    Node(const U& data) :
      d_data(data), d_next(nullptr) {}

    Node* next() { return d_next; }
    void setNext(Node* node) { d_next = node; }
    U& data() { return d_data; }

    U d_data;
    Node *d_next;
};

template <typename U>
class Iterator {

  public:
    Iterator(Node<U>* node) :
      d_node(node) {}

    U& operator*()
    {
	return d_node->data();
    }

    const U& operator*() const
    {
	return d_node->data();
    }

    U* operator->()
    {
	return &(d_node->data());
    }

    const U* operator->() const
    {
	return &(d_node->data());
    }

    Iterator<U>& operator++()
    {
	d_node = d_node->next();
	return *this;
    }

    Iterator<U>& operator++(int)
    {
	Iterator<U> copy(*this);
	++copy;
	return copy;
    }

    bool operator== (const Iterator<U>& rhs) const
    {
	return d_node == rhs.d_node;
    }

    bool operator!= (const Iterator<U>& rhs) const
    {
	return !(*this == rhs);
    }

  private:
    Node<U>* d_node;
};

template <typename T>
class List {

  public:

    typedef Iterator<T> iterator;
    typedef const Iterator<T> const_iterator;

    List() :
      d_front(nullptr) {}

    ~List() 
    {
	Node<T> *cursor = d_front;
	while (cursor != nullptr) {
	    Node<T>* tmp = cursor;
	    cursor = cursor->next();
	    delete tmp;
	}
    }

    iterator begin()
    {
	return iterator(d_front);
    }


    const_iterator cbegin() const
    {
	return const_iterator(d_front);
    }

    iterator end()
    {
	return iterator(nullptr);
    }

    const_iterator cend() const
    {
	return const_iterator(nullptr);
    }

    void push_front(const T& val)
    {
	Node<T> *toadd = new Node<T>(val, d_front);
	d_front = toadd;
    }

    void pop_front()
	// undefined behavior if list is empty
    {
	assert(!empty());

	Node<T> *nxt = d_front->next();
	delete d_front;
	d_front = nxt;
    }

    void push_back(const T& val)
    {
	if (empty()) {
	    push_front(val);
	}
	else {
	    Node<T> *cursor = d_front;
	    while (cursor->next() != nullptr) {
		cursor = cursor->next();
	    }

	    Node<T> *toadd = new Node<T>(val, nullptr);
	    cursor->setNext(toadd);
	}
    }

    void pop_back()
	// undefined behavior if list is empty
    {
	assert(!empty());

	Node<T> *cursor = d_front;
	if (cursor->next() == nullptr) {
	    // only one node in the list
	    delete d_front;
	    d_front = nullptr;
	    return;
	}

	while (cursor->next()->next() != nullptr) {
	    cursor = cursor->next();
	}
	delete cursor->next();
	cursor->setNext(nullptr);
    }

    bool empty() const
    {
	return d_front == nullptr;
    }

  private:

    Node<T> *d_front;

};

} // close namespace

#endif

