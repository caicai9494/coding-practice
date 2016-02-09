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
/*
class Solution
{
    public:
	int maxSubArray(vector<int>& nums)
	{
	    int backup, sum;
	    sum = 0;
	    backup = numeric_limits<int>::min();

	    unsigned int S = nums.size();
	    for(unsigned int i = 0; i < S; i++)
	    {
		sum += nums[i];

		if(backup < sum)
		    backup = sum;

		if(sum < 0) sum = 0;
	    }

	    return backup;
	}

};
*/

inline int max(int a, int b) { return a > b ? a : b; }

int maxSubRoutine(int A[], int left, int right) {
    if(left >= right) return A[left];

    int mid = (left + right) / 2;

    int lmax = maxSubRoutine(A, left, mid);
    int rmax = maxSubRoutine(A, mid + 1, right);

    
    int tempsum = 0,  leftsum, rightsum;
    leftsum = rightsum = INT_MIN;
    for(int i = mid; i >= left; i--) {
	tempsum += A[i];
	if(tempsum > leftsum) leftsum = tempsum;
    }

    tempsum = 0;
    for(int i = mid + 1; i <= right; i++) {
	tempsum += A[i];
	if(tempsum > rightsum) rightsum = tempsum;
    }

    int mmax = max(max(rightsum, leftsum), rightsum + leftsum);

    return max(max(lmax, rmax), mmax);
}

int maxSubArray(int A[], int n) {
    return maxSubRoutine(A, 0, n - 1);
}
int main()
{
    int A[] = {1, 1, -2};
    return 0;
}
