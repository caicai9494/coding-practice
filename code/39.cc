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
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	    sort(candidates.begin(), candidates.end());
	    vector<vector<int>> ret;
	    vector<int> temp;
	    rec(candidates, target, 0, temp, ret);
	    return ret;
	}
	void rec(vector<int>& candidates, int target, int start,  vector<int>& place, vector<vector<int>>& result) {
	    if(target == 0) {
		result.push_back(place);
	    }
	    else if(target > 0){
		for(size_t i = start; i < candidates.size(); ++i) {
		    place.push_back(candidates[i]);
		    rec(candidates, target - candidates[i], i, place, result);
		    place.pop_back();
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
    //vector<int> num = {2, 3, 6, 7};
    vector<int> num = {7, 3, 2};
    auto ret = s.combinationSum(num, 18);
    print(ret);
    //cout << s. << endl;
    return 0;
}
