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
  public:
    int addDigits(int num) 
    {
	// O(n)
	/*
	if (num < 10) {
	    return num;
	}

	int newval = 0;
	while (num > 0) {
	    newval += num % 10;
	    num /= 10;
	}
	return addDigits(newval);
	*/

	return (num - 1) % 9 - 1;
    }

};

int main()
{
    Solution s;
    DBG(s.addDigits(38));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
