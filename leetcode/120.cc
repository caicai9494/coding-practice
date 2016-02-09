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
	int minimumTotal(vector<vector<int> >&triangle)
	{
	    vector<vector<int> > result;
	    result.push_back(triangle[0]);
	    for(unsigned int r = 1; r < triangle.size(); r++) {
		vector<int> temp;
		for(unsigned int c = 0; c < triangle[r].size(); c++) {
		    int val;
		    if(c == 0) val = result[r-1][c] + triangle[r][c];
		    else if(c == triangle[r].size() - 1) val = result[r-1][c-1] + triangle[r][c];
		    else val = min(result[r-1][c-1] + triangle[r][c], result[r-1][c] + triangle[r][c]);
		    temp.push_back(val);
		}
		result.push_back(temp);
		temp.resize(0);
	    }

	    vector<int> lastrow = *result.rbegin();
	    return *min_element(lastrow.begin(), lastrow.end());
	}
};
