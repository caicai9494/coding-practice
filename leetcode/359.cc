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
  ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Logger {
  int d_window;
  unordered_map<string, int> d_history;

public:
  Logger(): d_window(10) {}

  bool shouldPrintMessage(int timestamp, const string& message) 
  {
      auto ret = d_history.find(message);
      if (ret == d_history.end()) {
	  d_history[message] = timestamp;
	  return true;
      }

      bool ans = timestamp - ret->second >= d_window; 
      if (ans) {
	  ret->second = timestamp;
      }
      return ans;
  }
};

/**
 *
 *  * Your Logger object will be instantiated and called as such:
 *
 *   * Logger obj = new Logger();
 *
 *    * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 *
 *     */

int main() {
  // int A[] = {5, 7, 7, 8, 8, 10};
  // vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
  // cout << s. << endl;
  return 0;
}
