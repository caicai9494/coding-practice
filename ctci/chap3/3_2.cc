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
class MinStack {
    // T must overload "==" and ">=".
  public:
    void push(const T& val) 
    {
	d_stack.push(val);

	if (d_minStack.empty() || d_minStack.top().first > val) {
	    d_minStack.push(std::make_pair(val, 1));
	}  
	else if (d_minStack.top().first == val) {
	    ++ d_minStack.top().second;
	}
	else {
	    // do nothing if 'val' is greator than 'min'
	}
    }
    void pop() 
	// undefined behaviour if 'MinStack' is empty
    {
	assert(!d_stack.empty());

	// check the min count
	// if count is 1 then pop the top
	// otherwise decrement
	if (d_stack.top() == d_minStack.top().first ) {
            if (d_minStack.top().second == 1) {
		d_minStack.pop();
	    }
	    else {
		-- d_minStack.top().second;
	    }
	}
	d_stack.pop();
    }

    T& top() 
    {
	return d_stack.top();
    }
    
    const T& top() const
    {
	return const_cast<const T*>(this)->top();
    }

    const T& min() const 
    {
	return d_minStack.top().first;
    }

  private:
    typedef std::pair<T, int> TCount;
    std::stack<TCount> d_minStack;
    std::stack<T> d_stack;
};

int main()
{
    MinStack<int> mstack;
    mstack.push(3);
    mstack.push(2);
    mstack.push(1);
    ASSERT_EQ(mstack.top(), 1);
    ASSERT_EQ(mstack.min(), 1);
    mstack.pop();
    ASSERT_EQ(mstack.top(), 2);
    ASSERT_EQ(mstack.min(), 2);
    mstack.pop();
    ASSERT_EQ(mstack.top(), 3);
    ASSERT_EQ(mstack.min(), 3);


    MinStack<int> mstack2;
    mstack2.push(1);
    mstack2.push(2);
    mstack2.push(3);
    ASSERT_EQ(mstack2.top(), 3);
    ASSERT_EQ(mstack2.min(), 1);

    const MinStack<int>& rmstack2 = mstack2;
    ASSERT_EQ(rmstack2.min(), 1);

    //ASSERT_TRUE("123" == "1231");

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
