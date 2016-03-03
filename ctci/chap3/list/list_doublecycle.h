#ifndef LIST_DOUBLECYCLE_H 
#define LIST_DOUBLECYCLE_H 

#include <cassert>

namespace LZ {

template <typename U> class Iterator;
template <typename T> class List;

template <typename U>
class Node {

    friend class Iterator<U>;
    friend class List<U>;

  private:

    Node() :
      d_next(nullptr), d_prev(nullptr) {}

    Node(const U& data, Node* next, Node* prev) :
      d_data(data), d_next(next), d_prev(prev) {}

    Node(const U& data) :
      d_data(data), d_next(nullptr), d_prev(nullptr) {}

    Node* next() { return d_next; }
    void setNext(Node* node) { d_next = node; }

    Node* prev() { return d_prev; }
    void setPrev(Node* node) { d_prev = node; }

    U& data() { return d_data; }

    U d_data;
    Node *d_next;
    Node *d_prev;
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

    Iterator<U>& operator--()
    {
	d_node = d_node->prev();
	return *this;
    }

    Iterator<U>& operator--(int)
    {
	Iterator<U> copy(*this);
	--copy;
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
      d_node(new Node<T>()) 
    {
	d_node->setNext(d_node);
	d_node->setPrev(d_node);
    }

    ~List() 
    {
	Node<T> *cursor = d_node->next();
	while (cursor != d_node) {
	    Node<T>* tmp = cursor;
	    cursor = cursor->next();
	    delete tmp;
	}
	delete d_node;
    }

    iterator begin()
    {
	return iterator(d_node->next());
    }


    const_iterator cbegin() const
    {
	return const_iterator(d_node->next());
    }

    iterator end()
    {
	return iterator(d_node);
    }

    const_iterator cend() const
    {
	return const_iterator(d_node);
    }

    void push_front(const T& val)
    {
	Node<T>* toadd = new Node<T>(val, d_node->next(), d_node);
	d_node->next()->setPrev(toadd);
	d_node->setNext(toadd); 
    }

    void pop_front()
	// undefined behavior if list is empty
    {
	assert(!empty());

	Node<T> *nxt = d_node->next();
	d_node->setNext(nxt->next());
	nxt->next()->setPrev(d_node);
	delete nxt;
    }

    void push_back(const T& val)
    {
	Node<T>* toadd = new Node<T>(val, d_node, d_node->prev());
	d_node->prev()->setNext(toadd);
	d_node->setPrev(toadd);
    }

    void pop_back()
	// undefined behavior if list is empty
    {
	assert(!empty());

	Node<T>* nxt = d_node->prev();
	d_node->setPrev(nxt->prev());
	nxt->prev()->setNext(d_node);
	delete nxt;
    }

    bool empty() const
    {
	return d_node->next() == d_node &&
	       d_node->prev() == d_node;
    }

  private:

    Node<T> *d_node;

};

} // close namespace

#endif

