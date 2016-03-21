#include <algorithm>
#include <cassert>
#include <limits>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool canWinNim(int n) 
    {
	assert(n > 0);
	return n % 4 > 0;
    }
};

int main()
{
    Solution s;
    cout << s.canWinNim(8) << '\n';
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}

