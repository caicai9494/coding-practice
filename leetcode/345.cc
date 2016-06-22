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
    string reverseVowels(string str) 
    {
	vector<char> temp = {'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U'};
	set<char> vowels(temp.begin(), temp.end());

	int i = 0;
	int j = str.size() - 1;
	while (i < j) {
	    while (i < j && vowels.find(str[i]) == vowels.end()) { ++i; }
	    while (i < j && vowels.find(str[j]) == vowels.end()) { --j; }
	    if (i < j) {
		swap(str[i], str[j]);
		++i;
		--j;
	    }
	}
	return str;
    }
};

int main()
{
    Solution s;
    DBG(s.reverseVowels("hello"));
    DBG(s.reverseVowels("el"));
    DBG(s.reverseVowels("oea"));
    DBG(s.reverseVowels("o"));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
