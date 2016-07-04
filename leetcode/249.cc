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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
  public:
    vector<vector<string>> groupStrings(const vector<string>& strings) 
    {
	vector<vector<string>> ret;

	map<pair<int/*len*/, int/*shift*/>, vector<const string*>> table;
	for (auto it = strings.begin(); it != strings.end(); ++it) {
	    int len = it->size();
	    int shift = 0;
	    for (int i = 1; i < len; ++i) {
		int diff = (*it)[i] - (*it)[i-1] + 26;
		shift += (diff % 26);
	    }
	    table[make_pair(len, shift)].push_back(&*it);
	}

	for (auto it = table.begin(); it != table.end(); ++it) {
	    vector<string> tmp;
	    tmp.reserve(it->second.size());
	    for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
		tmp.push_back(**it2);
	    }
	    ret.push_back(tmp);
	}

	return ret;
    }
};

int main()
{
    Solution s;
    //auto ret = s.groupStrings({"abc", "bcd", "ab", "bc", "cd", "efcd", "dc", "ba"});
    auto ret = s.groupStrings({"za", "cb", "ab"});
    for (auto& vec: ret) {
	DBG(vec);
    }
    DBG(-25 % 24);
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
