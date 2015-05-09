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
	int jump(vector<int>& nums) {
	    int last = 0;
	    int current = 0;
	    int step = 0;

	    for(int i = 0; i < nums.size()-1; i++) {
		current = max(current, i + nums[i]);
		if(i == last) { 
		    last = current;
		    step++;
		}
	    }
	    return step;
	}

};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {2, 3, 1, 1 , 4};
    //vector<int> num = {3, 2, 1, 0 , 4};
    //vector<int> num = {1, 2, 1, 1, 1};
    vector<int> num = {1, 2, 0, 1};
    cout << (s.jump(num)) << endl;
    return 0;
}
