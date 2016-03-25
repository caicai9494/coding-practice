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
    // dynamic programming I
    // fibonacci 
  public:
    unsigned fibonacciSlow(unsigned n)
    {
	if (n < 3) { 
	    return 1;
	}
	else {
	    return fibonacciSlow(n-1) + fibonacciSlow(n-2);
	}
    }

    unsigned fibonacci(unsigned n)
    {
	assert(n != 0);

	unordered_map<unsigned, unsigned> table;
	table[1] = 1;
	table[2] = 1;

	auto it = table.find(n);
	if (it != table.end()) {
	    return it->second;
	}
	else {
	    unsigned next = fibonacci(n - 1) + fibonacci(n - 2);
	    table[n] = next;
	    return next;
	}
    }
  private:
};

int main()
{
    Solution s;
    //DBG(s.fibonacciSlow(100));
    // doesn't terminate after 10 secs 
     
    for (int i = 1; i < 30; ++i) {
	DBG(s.fibonacci(i));
    }

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
