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

class Solution {
  public:
#ifdef USE_LOOP
    bool isPowerOfTwo(int n) 
    {
	if (n == 0) { return false; }
	if (n == 1) { return true; }
	if (n % 2 == 0) { return isPowerOfTwo(n>>1); }
	else { return false; }
    }
#endif
    bool isPowerOfTwo(int n) 
    {
	if (n == 0) { return false; }
	double rem = log(n) / log(2);
	return floor(rem) == rem;
    }
};

int main()
{
    Solution s;
    s.isPowerOfTwo(2);
    DBG(2&0x1);
    ASSERT_TRUE(2 & 0x1 == 0);
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
