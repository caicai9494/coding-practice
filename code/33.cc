#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>
#include <set>

using namespace std;
class Solution
{
    public:
	int search(int A[], int n, int target) {
	    int l = 0;
	    int r = n - 1;
	    int m;

	    while(l < r) {
		m = (l + r) / 2;
		if(A[m] == target) return m;

		if(A[m] >= A[r]) {
		    if(A[m] > target && target >= A[l]) r = m - 1;
		    else l = m + 1;
		} else {
		    if(A[m] < target && target <= A[r]) l = m + 1;
		    else r = m - 1;
		}
	    }
	    return -1;
	}

};
