
#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>

using namespace std;
class Solution
{
    public:
	vector<vector<int> > triangle;

	vector<int> getRow(int rowIndex)
	{
	    if(rowIndex < 0) return vector<int>();
	    vector<int> temp = {1};
	    triangle.push_back(temp);

	    int numRows = rowIndex;
	    for(int i = 1; i <= numRows; i++)
	    {
		vector<int> temp = {1};
		for(unsigned int num = 0; num < triangle[i-1].size() - 1; num++)
		    temp.push_back(triangle[i-1][num] + triangle[i-1][num+1]);
		temp.push_back(1);
		triangle.push_back(temp);
	    }

	    return triangle[rowIndex];
	}

};

int main()
{
    Solution s;
    return 0;
}
