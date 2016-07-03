#include <algorithm>
#include <cassert>
#include <limits>
#include <list>
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

class MovingAverage {

    const int d_window;
    int d_size;
    list<int> d_store;
    double d_ret;
    
  public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : d_window(size), d_size(0), d_ret(0)
    {
    }

    double next(int val) 
    {
	if (d_size < d_window) {
	    d_store.push_back(val);
	    d_size++;
	    d_ret = (d_ret * (d_size - 1) + val) / d_size;
	}
	else {
	    d_ret = (d_ret * d_size - d_store.front() + val) / d_window;
	    d_store.pop_front();
	    d_store.push_back(val);
	}
	return d_ret;
    }



};

class Solution {
  public:
};

int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
