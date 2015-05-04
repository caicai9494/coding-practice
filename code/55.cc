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
	/* backtracking bad idea
	bool canJump(vector<int>& nums, int inx) {
	    int len = nums.size()-1;
	    if(len == inx) return true;
	    else if(len < inx) return false;
	    
	    int steps = nums[inx];
	    for(int i = steps; i >= 1; --i) {
		if(canJump(nums, inx + i))
		    return true;
	    }
	    return false;
	}
	*/
	bool canJump(vector<int>& nums) {
	    int len = nums.size() - 1;
	    if(len == 0) return true;

	    int maxDist = nums[0];
	    for(int i = 0; i <= maxDist; ++i) {
		if(nums[i] + i >= maxDist) {
		    if(nums[i] + i >= len) 
			return true;
		    else maxDist = nums[i] + i;
		}
	    }
	    return false;

	}

};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {2, 3, 1, 1 , 4};
    vector<int> num = {3, 2, 1, 0 , 4};
    cout << (s.canJump(num)) << endl;
    return 0;
}
