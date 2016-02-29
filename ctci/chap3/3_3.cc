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

template <typename T, size_t CAPACITY>
class SetOfStack {

  public:

    SetOfStack() :
	d_capacity(CAPACITY), d_pos(0) 
    {
	d_stacks.push_back(std::stack<T>());
    }

    ~SetOfStack() {}

    bool empty() const 
    {
	return d_pos != 0 ? false : d_stacks[0].empty();
    }

    void pop()
	// undefined behaviour if empty
    {
	assert(!empty());

	// remove the top stack if empty
	if (d_stacks[d_pos].empty()) {
	    d_stacks.pop_back();

	    // decrement if not zero
	    if (d_pos > 0) {
		--d_pos;
	    } 
	}
    }

    void push(const T& val)
    {
	if (d_stacks[d_pos].size() >= d_capacity) {
	    d_stacks.push_back(std::stack<T>());
	    d_stacks.back().push(val);
	    ++d_pos;
	}
	else {
	    d_stacks.back().push(val);
	}
    }

    const T& top() const 
	// undefined behaviour if empty
    {
	assert(!empty());

	return d_stacks[d_pos].top(); 
    }

  private:
    size_t d_capacity;
    size_t d_pos;
    std::vector<std::stack<T> > d_stacks;

};

int main()
{
    SetOfStack<int, 1> sstack;
    ASSERT_EQ(sstack.empty(), true);

    const SetOfStack<int, 1>& rsstack = sstack;
    ASSERT_EQ(rsstack.empty(), true);

    sstack.push(1);
    sstack.push(2);
    sstack.push(3);
    ASSERT_EQ(sstack.top(), 3);

    sstack.pop();
    ASSERT_EQ(sstack.top(), 2);
    //ASSERT_TRUE("123" == "1231");

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
