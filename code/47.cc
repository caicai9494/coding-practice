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
	vector<vector<int>> permuteUnique(vector<int>& nums) {
	    sort(nums.begin(), nums.end());
	    vector<int> temp;
	    vector<size_t> iii;
	    vector<vector<int>> result;

	    permutation(nums, 0, temp, result);
	    return result;
	}
	void permutation(const vector<int>& nums, size_t index, vector<int>& place, vector<vector<int>>& result) {
	    if(index == nums.size()) result.push_back(place);
	    else {
		for(size_t i = 0; i < nums.size(); ++i) if(i == 0 || nums[i] != nums[i-1]) {
		    size_t c1 = 0, c2 = 0;
		    for(size_t j = 0; j < index; j++) if(nums[i] == place[j]) ++c1; 
		    for(size_t j = 0; j < nums.size(); j++) if(nums[i] == nums[j]) ++c2; 
		    if(c1 < c2) {
			place.push_back(nums[i]);
			permutation(nums, index+1, place, result);
			place.pop_back();
		    }
		}
	    }
	}

};
    void print(vector<vector<int>>& result) {
	for(auto& v : result) {
	    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	    cout << endl;
	}
    }
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    vector<int> num = {-1, 2, -1, 2 , 1, -1, 2, 1};
    auto vvv = s.permuteUnique(num);
    print(vvv);
    return 0;
}
