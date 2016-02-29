#include <algorithm>
#include <assert.h>
#include <bitset>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <tool/lz_test.h>

template <typename T>
class Queue {

  public:

    void push_back(const T& val)
    {
	d_inStack.push(val);
    }

    void pop_front()
	// undefined behaviour if empty
    {
	assert(!d_inStack.empty() || !d_outStack.empty());
	
	if (d_outStack.empty()) {
	    exchange();
	}

	d_outStack.pop();
    }

    T& front() 
	// undefined behaviour if empty
    {
	assert(!d_inStack.empty() || !d_outStack.empty());

	if (d_outStack.empty()) {
	    exchange();
	}
	return d_outStack.top();
    }

  private:
    std::stack<T> d_inStack;
    std::stack<T> d_outStack;

    void exchange()
	// from 'inStack' to 'outStack'
    {
	while (!d_inStack.empty()) {
	    T top = d_inStack.top();
	    d_inStack.pop();
	    d_outStack.push(top);
	}
    }

};

int main()
{
    Queue<int> queue;
    queue.push_back(1);
    queue.push_back(2);
    queue.push_back(3);

    ASSERT_EQ(queue.front(), 1);

    queue.pop_front();
    ASSERT_EQ(queue.front(), 2);
    //ASSERT_TRUE("123" == "1231");

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
