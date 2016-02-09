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
	vector<vector<int>>result;
	vector<vector<int>> subsetsWithDup(vector<int> &S)
	{
	    vector<int> place;
	    sort(S.begin(), S.end());
	    sub(S, 0, place);

	    return result;
	}

	void sub(vector<int> &S, int begin, vector<int> &place)
	{
	    result.push_back(place);

	    for(size_t i = begin; i < S.size(); i++) if(i == begin || S[i] != S[i-1])
	    {
		place.push_back(S[i]);
		sub(S, i+1, place);
		place.pop_back();
	    }
	}
};

void print(vector<vector<int>>& result) {
    for(auto& v : result) {
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
    }
}

int main() {
    Solution s;
    //vector<int> num = {1,2,3,4};
    vector<int> num = {1,2,2};
    //vector<int> num = {1,1};
    auto vv = s.subsetsWithDup(num);
    print(vv);
    return 0;
}

