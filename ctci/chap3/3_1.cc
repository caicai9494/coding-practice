#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <tool/lz_test.h>

template <typename T, size_t N>
class NWayStack {

    // This class provides access to multiple stacks

  public:

    NWayStack() : d_n(N), d_indices(std::vector<int>(N, -1)) {}
    ~NWayStack() 
    {
	for (size_t i = 0; i != d_nodes.size(); ++i) {
	    delete d_nodes[i];
	}
    }

    bool emptyNth(size_t n) const
    {
	return d_indices[n] == -1;
    }

    void popNth(size_t n)
	// undefined behaviour if Nth stack is empty
    {
	assert(!emptyNth(n));

	// delete the old node,
	// cache the index to be deleted
	int index = d_indices[n];
	d_indices[n] = d_nodes[index]->d_previous;
	delete d_nodes[index];
	d_nodes[index] = nullptr;
	d_deleted.push_back(index);
    }

    void pushNth(size_t n, const T& val)
    {
	int index = d_indices[n];

	if (d_deleted.empty()) { 
	    d_nodes.push_back(new Node<T>(val, index));
	    d_indices[n] = d_nodes.size() - 1;
	}
	else {
	    // fetch the deleted index
	    // and allocate the node
	    int pos = d_deleted.back();
	    d_deleted.pop_back();
	    d_nodes[pos] = new Node<T>(val, index);
	    d_indices[n] = pos;

	}
    }

    const T& topNth(size_t n) const
	// provide non-modifiable access
    {
	return d_nodes[d_indices[n]]->d_data;
    }

  private:
    const size_t d_n;
    std::vector<int> d_indices;
    std::vector<int> d_deleted;

    template <typename U>
    class Node {
	friend class NWayStack<T, N>;
      private:
        T d_data;
	int d_previous;
	Node(const T& data, int prev) :
	    d_data(data), d_previous(prev) {}
    };

    std::vector<Node<T>* > d_nodes;

};

int main()
{
    NWayStack<int, 3> stack;
    ASSERT_EQ(true, stack.emptyNth(0));
    ASSERT_EQ(true, stack.emptyNth(1));
    ASSERT_EQ(true, stack.emptyNth(2));

    stack.pushNth(0, 1);
    stack.pushNth(0, 2);
    ASSERT_EQ(2, stack.topNth(0));
    stack.popNth(0);
    ASSERT_EQ(1, stack.topNth(0));

    stack.pushNth(1, 1);
    stack.pushNth(1, 2);
    ASSERT_EQ(2, stack.topNth(1));

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
