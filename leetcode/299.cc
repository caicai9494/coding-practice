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
    string getHint(const string& secret, const string& guess) {
	assert(secret.size() == guess.size());

	int bows = 0;
	int cows = 0;
	vector<int> table(10, 0);
	for (int i = 0; i < secret.size(); ++i) {
	    ++table[secret[i] - '0'];
	}

	for (int i = 0; i < secret.size(); ++i) {
	    if (secret[i] == guess[i]) { 
		++bows; 
		--table[secret[i] - '0'];
	    }
	}

	for (int i = 0; i < secret.size(); ++i) {
	    if (secret[i] != guess[i] && table[guess[i] - '0'] > 0) {
		--table[guess[i] - '0'];
		++cows;
	    }
	}
	return to_string(bows) + "A" + to_string(cows) + "B";
    }
};

int main()
{
    Solution s;
    DBG(s.getHint("1123", "0111"));
    DBG(s.getHint("1807", "7801"));
    DBG(s.getHint("1807", "7810"));
    DBG(s.getHint("1122", "1222"));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
