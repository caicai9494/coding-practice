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
	int maxSubArray(int A[], int n)
	{
	    int maxele, backup, sum;
	    backup = sum = 0 ;
	    maxele = numeric_limits<int>::min();

	    for(int i = 0; i < n; i++)
	    {
		if(maxele < A[i]) maxele = A[i];

		sum += A[i];
		if(sum < 0) sum = 0;

		if(backup < sum)
		    backup = sum;
	    }

	    if(!sum) return maxele;
	    return backup;
	}

};
int main()
{
    Solution s;
    int A[] = {1, 1, -2};
    cout << s.maxSubArray(A, 3) << endl;
    return 0;
}
