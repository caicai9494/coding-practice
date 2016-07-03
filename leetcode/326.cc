#include <algorithm>
#include <cassert>
#include <cmath>
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
#ifdef USE_LOOP
    bool isPowerOfThree(int n) 
    {
	if (n == 0) { return false; }
	if (n == 1) { return true; }
	if (n % 3 == 0) { return isPowerOfThree(n/3); }
	else { return false; }
    }
#endif
    bool isPowerOfThree(int n) 
    {
	if (n == 0) { return false; }
	double rem = log(n) / log(3);
	return floor(rem) == rem;
    }
};

int main()
{
    Solution s;
    s.isPowerOfThree(0);
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
