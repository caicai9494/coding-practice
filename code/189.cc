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
	void rotate(vector<int>& nums, int k) {
	    vector<int> clone(nums);
	    size_t N = nums.size();
	    int K = k % N;
	    copy(nums.end() - K, nums.end(), clone.begin());
	    copy(nums.begin(), nums.begin() + nums.size() - K, clone.begin() + K);
	    swap(nums, clone);
	}

};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    vector<int> num = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(num, 3);
    for(auto& i : num) cout << i << endl;
    return 0;
}
