#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <iterator>
#include <stack>
#include <bitset>
#include <set>

using namespace std;
class Solution
{
    public:
	string largestNumber(vector<int> num)
	{
	    vector<string> svector;
	    transform(num.begin(), num.end(), back_inserter(svector), [](int n) { return to_string(n); }); 
	    sort(svector.begin(), svector.end(), [&](const string &lhs, const string &rhs)
	    {
	        return lhs + rhs < rhs + lhs;
	    });
	    string ret;
	    ret = accumulate(svector.rbegin(), svector.rend(), string(), plus<string>());

	    bool flag = true;
	    for(auto& c : ret) {
		if(c != '0') flag = false;
		if(!flag) break;
	    }

	    return flag == true ? "0" : ret;
	}

};
int main()
{
    Solution s;
    cout << s.largestNumber({12, 121});
    cout << s.largestNumber({99, 991});
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
