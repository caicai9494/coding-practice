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
	bool searchMatrix(vector<vector<int> > &matrix, int target)
	{
	    int left, right, mid;
	    left = 0, right = matrix.size() - 1;

	    while(left <= right)
	    {
		mid = (left + right) / 2;
		if(*(matrix[mid].begin()) <= target && target <= *(matrix[mid].rbegin()))
		    return find(matrix[mid], target);
		else if(*(matrix[mid].begin()) > target) right = mid - 1;
		else left = mid + 1;
	    }
	    return false;
	}
	bool find(vector<int> &array, int target)
	{
	    int left, right, mid;
	    left = 0, right = array.size() - 1;

	    while(left <= right)
	    {
		mid = (left + right) / 2;
		if(array[mid] == target)
		    return true;
		else if(array[mid] < target)
		    left = mid + 1;
		else right = mid - 1;
	    }
	    return false;
	}
};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {0,1,2,4, 5, 6, 7 , 8};
    vector<int> num = {1,3};
    if(s.find(num, 1))
    cout << "yes" << endl;
    return 0;
}
