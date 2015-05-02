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
#include <unordered_set>

using namespace std;
class Solution
{
    public:
	bool wordBreak(string s, const unordered_set<string>& dict) {
	    size_t len = s.length();

	    vector<vector<bool> > grid;
	    for(size_t i = 1; i <= len; ++i) {
		vector<bool> temp;
		auto END = dict.end();
		for(size_t j = 0; j + i <= len; ++j) {
		    temp.push_back(dict.find(s.substr(j, i)) != END);
		}
		grid.push_back(temp);
	    }


	    vector<bool> result(len, false);
	    result[0] = grid[0][0];

	    for(size_t i = 1; i < len; ++i) {
		result[i] = grid[i][0];
		if(result[i]) continue;
		for(size_t j = 1; j <= i; j++) {
		    if(result[i]) break;
		    result[i] = result[i] || (result[i-j] && grid[j-1][i-j+1]);   
		}
	    }

	    /*
	    for(auto& g : grid) {
		for(auto b : g) {
		    
		    if(b) cout << "1 ";
		    else cout << "0 ";
		}
		cout << endl;
	    }
	    for(auto b : result) {
		    if(b) cout << "1 ";
		    else cout << "0 ";
	    }
	    cout << endl;
	    */
	    
	    return *result.rbegin();
	}
};
int main()
{
    Solution s;
    cout << (s.wordBreak("leetcode", {"leet","code"})) << endl;
    cout << (s.wordBreak("abcd", {"a","abc", "b", "cd"})) << endl;
    cout << (s.wordBreak("dogs", {"dog","s", "gs"})) << endl;
    return 0;
}
