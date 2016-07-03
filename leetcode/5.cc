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
    pair<int, int> expand(const string& str, int c1, int c2)
    {
	int l = c1;
	int r = c2;
	while (l >= 0 && r < str.size() && str[l] == str[r]) {
	    --l;
	    ++r;
	}
	return make_pair(l+1, r-1);
    }
    string longestPalindrome(const string& str) 
    {
	if (str.empty()) {
	    return str;
	}

	int max = 0;
	auto lr = make_pair(0, 1);
	for (int i = 1; i < str.size(); ++i) {
	    auto pr = expand(str, i, i); 
	    if (pr.second - pr.first > max) {
		lr = pr;
		max = pr.second - pr.first;
	    }

	    pr = expand(str, i-1, i); 
	    if (pr.second - pr.first > max) {
		lr = pr;
		max = pr.second - pr.first;
	    }
	}

	return str.substr(lr.first, lr.second-lr.first+1);
    }
};

int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
