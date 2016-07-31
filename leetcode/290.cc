#include <algorithm>
#include <cassert>
#include <limits>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#include "lz_error.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
  public:
    bool wordPattern(const string& pattern, const string& str) {
	vector<string> tokens;
	stringstream ss;
	ss << str;
	string token;
	while (getline(ss, token, ' ')) {
	    tokens.push_back(token);
	}

	if (tokens.size() != pattern.size()) {
	    return false;
	}

	unordered_map<char, string> table;
	unordered_map<string, char> duptable;
	for (size_t i = 0; i != pattern.size(); ++i) {
	    auto isdup = duptable.find(tokens[i]);
	    if (isdup != duptable.end() && isdup->second != pattern[i]) {
		return false;
	    }
	    else {
		duptable[tokens[i]] = pattern[i];
	    }

	    auto ret = table.find(pattern[i]);
	    if (ret == table.end()) {
		table[pattern[i]] = tokens[i];
	    }
	    else if (ret->second != tokens[i]) {
		return false;
	    }
	}
	return true;
    }
};

int main()
{
    Solution s;
    s.wordPattern("aaa", "abc bcd efg ssd");
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
