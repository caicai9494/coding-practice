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
    double myPow(double x, int n) 
    {
	if (n < 0) {
	    if (n == std::numeric_limits<int>::min()) {
		return myPow(1/x/x, -(n+1));
	    }
	    else {
		return myPow(1/x, -n);
	    }
	}
	else if (n == 0) {
	    return 1;
	}
	else if (n % 2 == 0) { // is even
	    double pow = myPow(x, n/2);
	    return pow * pow;
	}
	else { // is odd
	    return x * myPow(x, n - 1);
	}
	   
    }
};

int main()
{
    Solution s;
    DBG(s.myPow(2,5));
    DBG(s.myPow(2,1));
    DBG(s.myPow(2,0));
    DBG(s.myPow(2,0));
    DBG(s.myPow(2,-1));
    DBG(s.myPow(2.2,-10));
    DBG(s.myPow(0.001, std::numeric_limits<int>::max()));
    DBG(s.myPow(2, std::numeric_limits<int>::min()));
    DBG(s.myPow(8.88023,3));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
