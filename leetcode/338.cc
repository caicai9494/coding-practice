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

    vector<int> table;

    const vector<int>& countBits(int num) 
    {
	table.push_back(0);
	int sq = 1;
	for (int i = 1; i <= num; ++i) {
	    if (sq == i) {
		table.push_back(1);
		sq <<= 2;
	    }	
	    else {
		assert(sq > i);
                DBG(1 + table[i - sq/2]);
		table.push_back(1 + table[i - sq/2]);
	    }
	}

	return table;
    }
};

int main()
{
    Solution s;
    DBG(s.countBits(123456));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
