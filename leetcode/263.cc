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
    bool isUgly(int num) 
    {
	if (num == 0) return false;
	if (num == 1 || num == 2 || num == 3 || num == 5) return true;
	if (num % 2 == 0) { return isUgly(num / 2); }
	if (num % 3 == 0) { return isUgly(num / 3); }
	if (num % 5 == 0) { return isUgly(num / 5); }
	return false;
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
