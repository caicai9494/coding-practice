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
    vector<int> searchRange(int A[], int n, int target) {
	vector<int> res;
	int left = 0; 
	int right = n - 1;

	int mid = (left + right) / 2;

	while(left < right)
	{
	    if(A[mid] < target)
		left = mid + 1;
	    else if(A[mid] > target)
		right = mid - 1;
	    else break;
	    mid = (left + right) / 2;
	}

	if(A[mid] == target)
	{
	    left = mid;
	    while(left > 0 && A[left] == A[left-1])
		left --;

	    right = mid;
	    while(right < n-1 && A[right] == A[right+1])
		right ++;

	}
	else
	    left = right = -1;

	res.push_back(left);
	res.push_back(right);
	
	return res;
    }
};
int main()
{
    Solution s;
    int A[] = {5, 7, 7, 8, 8, 10};
    //int A[] = {1};
    auto res = s.searchRange(A, 6, 8);
    cout << res[0] << endl;
    cout << res[1] << endl;
    return 0;
}
