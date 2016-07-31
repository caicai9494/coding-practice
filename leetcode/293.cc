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
    vector<string> generatePossibleNextMoves(const string& str) 
    {
	vector<string> ret;
	for (int i = 0; i < (int)str.size() - 1; ++i) {
	    if (str[i] == '+' && str[i+1] == '+') {
		string cpy = str;
		cpy[i] = '-';
		cpy[i+1] = '-';
		ret.emplace_back(cpy);
	    }
	}
	return ret;
    }
};

int main()
{
    Solution s;
    auto ret = s.generatePossibleNextMoves("") ;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
