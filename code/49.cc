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
#include <unordered_map>

using namespace std;
class Solution
{
    private:
	unordered_map<string, vector<string>> hash_;
    public:
	vector<string> anagrams(vector<string>& strs) {
	    for(auto &s : strs) {
		string clone(s);
		sort(clone.begin(), clone.end());
		if(hash_.find(clone) == hash_.end()) {
		    hash_[clone] = {};
		} 
		hash_[clone].push_back(s);
	    }

	    vector<string> ret;
	    for(auto &pair : hash_) {
		auto target = pair.second;
		if(target.size() > 1)  {
		    ret.reserve(ret.size() + target.size());
		    ret.insert(ret.end(), target.begin(), target.end()); 
		}
		   
	    }

	    return ret;
	}

};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    return 0;
}
