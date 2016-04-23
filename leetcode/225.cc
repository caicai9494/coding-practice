#include <algorithm>
#include <cassert>
#include <limits>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "lz_error.h"

using namespace std;

class Solution {
    queue<pair<int, bool> > d_queue;
    int d_top;

    void swap()
    {
    }

  public:
    void push(int x) 
    {
	d_top = x;
	d_queue.push(make_pair(x, true));
    }

    void pop()
    {
	assert(!empty());
	d_queue.push(make_pair(0, false));

	auto first = make_pair(0, false);
	auto second = make_pair(0, false);

	while (true) {
	    auto front = d_queue.front();
	    if (!front.second) {
		d_queue.pop();
		break;
	    }

	    d_queue.pop();

	    if (first.second) {
		d_queue.push(first);
	    }

	    first = second;
	    second = front;
	}

	if (first.second) {
	    d_top = first.first;
	    d_queue.push(first);
	}
    }

    int top() const
    {
	assert(!empty());
	return d_top;
    }

    bool empty() const
    {
	return d_queue.empty();
    }
};

int main()
{
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    DBG(s.top());
    s.pop();
    DBG(s.top());
    s.pop();
    DBG(s.top());
    DBG(s.empty());

    /*
    s.push(1);
    s.pop();
    DBG(s.empty());
    */
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
