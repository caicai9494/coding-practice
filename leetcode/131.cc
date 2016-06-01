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
    bool isPalindrome(const string& str) 
    {
	if (str.empty()) {
	    return true;
	}

	size_t first = 0;
	size_t last = str.size();
	while (first < last) {
	    if (str[first++] != str[--last]) {
		return false;
	    }
	} 
	return true;
    }	

    vector<vector<string>>& partition(const string &str) 
    {
	vector<string> tmp;
	partition(str, tmp);
	return d_data;
    }

    void partition(const string &str, vector<string>& cache) 
    {
	if (str.empty()) {
	    d_data.push_back(cache);
	    return;
	}

	for (size_t i = 1; i <= str.size(); ++i) {

	    auto left = str.substr(0,i);
	    if (isPalindrome(left)) {

		auto right = str.substr(i);

		cache.push_back(left);
		partition(right, cache);
	    }	
	    cache.clear();
	}

    }

    vector<vector<string>> d_data;

};

int main()
{
    Solution s;
    ASSERT_TRUE(true == s.isPalindrome("a"));
    ASSERT_TRUE(false == s.isPalindrome("ac"));
    ASSERT_TRUE(true == s.isPalindrome("aabaa"));
    ASSERT_TRUE(true == s.isPalindrome("abba"));
    //int A[] = {5, 7, 7, 8, 8, 10};
    vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    vector<vector<int>> nnn = {{1,2,3}, {4,5,6}, {5,6,7}};

    auto ret = s.partition("cdd");
    for (auto vec : ret) {
	cout << vec << '\n';
    }

    return 0;
}
