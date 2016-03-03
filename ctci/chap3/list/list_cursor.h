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

    Node() : 
      d_next(nullptr) {}

    U d_data;
    Node *d_next;

  public:

    Node* next() { return d_next; }
    const Node* next() const { return d_next; }
    void setNext(Node* node) { d_next = node; }
    U& data() { return d_data; }
};

template <typename T>
class List {

  public:

    List() :
      d_last(nullptr), d_prev(nullptr) {}

    ~List() 
    {
	Node<T> *cursor = d_head.next();
	while (cursor != nullptr) {
	    Node<T>* tmp = cursor;
	    cursor = cursor->next();
	    delete tmp;
	}
    }

    Node<T>* getNext()
    {
	if (d_prev == nullptr || d_prev->next() == nullptr) {
	    d_prev = &d_head;
	    return d_prev->next();
	    // return the head
	    // but don't forward the 'd_prev'
	}
	else {
	    d_prev = d_prev->next();
	    return d_prev->next();
	}

    }

    Node<T>* getEnd()
    {
	return nullptr;
    }

    void rewind()
    {
	d_prev = &d_head;
    }

    void removeCurrent()
	// must be called after calling 'getNext'
    {
	if (nullptr == d_prev) {
	    return;
	}

	Node<T>* todelete = d_prev->next();
	d_prev->setNext(todelete->next());
	delete todelete;
    }

    void push_back(const T& val)
    {
	Node<T> *toadd = new Node<T>(val, nullptr);
	if (empty()) {
	    d_head.setNext(toadd);
	    d_last = toadd;
	}
	else {
	    d_last->setNext(toadd);
	    d_last = toadd;
	}
    }

    void merge(List<T>& lst)
	// 'lst' will be invalidated after merge
    {
	d_last->setNext(lst.d_head.next());
	lst.d_head.setNext(nullptr);
    }

    /*
    void rewind() 
    {
	if (empty()) {
	    return nullptr;
	}
	d_prev = &d_head;
    }
    */

    bool empty() const
    {
	return d_head.next() == nullptr;
    }

  private:

    Node<T> d_head;
    Node<T> *d_last;

    Node<T> *d_prev;

};

} // close namespace

#endif

