#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>

using namespace std;
class Solution {
public:
    int search(int A[], int left, int right, int target)
    {
	if(left > right)
	{
	    if(target > A[right])
		return right + 1;
	    else return left;
	}

	int mid = (left + right) / 2;

	if(A[mid] > target)
	    return search(A, left, mid-1, target);
	else if(A[mid] < target)
	    return search(A, mid+1, right, target);
	else 
	    return mid;

    }

    int searchInsert(int A[], int n, int target) {
	return search(A, 0, n-1, target);
	/*
	int left = 0;
	int right = n - 1;
	int mid;

	while(left <= right)
	{
	    if(right - left < 1 && A[left] != target)
	    {
		if(A[left] > target)
		    return left;
		else
		    return right;
	    }

	    mid = (left + right) / 2;
	    if(A[mid] < target)
		left = mid;
	    else if(A[mid] > target)
		right = mid;
	    else break;
	}
	return mid;
	*/

    }
};
int main()
{
    Solution s;
    int A[] = {1, 2, 3, 4};
    cout << s.searchInsert(A, 4, 6) << endl;
    return 0;
}
