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
	    int all_neg = 1;
	    int low = A[0];;
	    for(int i = 0; i < n; i++)
	    {
		if(low < A[i])
		    low = A[i];

		if(A[i] >= 0)
		{
		    all_neg = 0;
		    break;
		}
	    }

	    if(!all_neg)
	    {

		int sum = 0, last = 0;
		for(int i = 0; i < n; i++)
		{
		    sum += A[i];
		    if(sum < 0)
			sum = 0;

		    if(sum > last)
			last = sum;
		}

		return last;

	    }
	    else
		return low;

	}

};
int main()
{
    Solution s;
    int A[] = {5, -7, -7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    cout << s.maxSubArray(A,6) << endl;
    return 0;
}
