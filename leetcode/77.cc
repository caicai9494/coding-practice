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
	vector<vector<int>> combine(int n, int k) {
	    vector<int> temp;
	    vector<vector<int>> result;

	    /*
	    if(n == k) {
		for(int i = 1; i <= n; ++i) temp.push_back(i);
		result.push_back(temp);
		return result;
	    }
	    */

	    rec(result, 1, n, k, temp);
	    return result;
	}

	void rec(vector<vector<int>>& result, int start, int n, int k, vector<int>& place) {
	    if(k == place.size()) result.push_back(place);
	    else {
		for(size_t i = start; i <= n; ++i) {
		    place.push_back(i);
		    rec(result, i+1, n, k, place);
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
    auto ret = s.combine(4,4);
    //auto ret = s.combine(4,2);
    //auto ret = s.combine(2,1);
    print(ret);
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    return 0;
}
