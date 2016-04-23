#include <algorithm>
#include <cassert>
#include <limits>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "lz_error.h"

using namespace std;

class Solution {
    stack<int> d_stack;
    stack<int> d_backup;

    void swap()
    {
	assert(d_backup.empty());
	while (!d_stack.empty()) {
	    d_backup.push(d_stack.top());
	    d_stack.pop();
	}
    }

  public:
    void push(int x)
    {
	d_stack.push(x);
    }

    void pop()
    {
	assert(!empty());
	if (d_backup.empty()) {
	    swap();
	}
	d_backup.pop();
    }

    int peak()
    {
	assert(!empty());
	if (d_backup.empty()) {
	    swap();
	}
	return d_backup.top();
    }

    bool empty()
    {
	return d_stack.empty() && d_backup.empty();
    }
};

int main()
{
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    DBG(s.peak());

    s.pop();
    DBG(s.peak());

    s.pop();
    DBG(s.peak());

    DBG(s.empty());
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
