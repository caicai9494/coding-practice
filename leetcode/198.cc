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
	int rob(vector<int> &num)
	{
	    int l = num.size();
	    if(!l) return 0;

	    vector<int> path;

	    if(l == 1) return num[0];
	    path.push_back(num[0]);

	    if(l == 2) return max(num[0], num[1]);
	    path.push_back(max(num[0], num[1]));

	    for(unsigned int i = 2; i < l; i++)
		path.push_back(max(path[i - 1], path[i-2] + num[i]));

	    return *path.rbegin();
	}


};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    cout << s. << endl;
    return 0;
}
