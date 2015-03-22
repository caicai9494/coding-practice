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

	vector<vector<int> > generate(int numRows)
	{
	    if(numRows <= 0) return triangle;
	    vector<int> temp = {1};
	    triangle.push_back(temp);

	    if(numRows == 1) 
	    {
		return triangle;
	    }
	    else for(int i = 1; i < numRows; i++)
	    {
		vector<int> temp = {1};
		for(unsigned int num = 0; num < triangle[i-1].size() - 1; num++)
		    temp.push_back(triangle[i-1][num] + triangle[i-1][num+1]);
		temp.push_back(1);
		triangle.push_back(temp);
	    }

	    return triangle;
	}

};
int main()
{
    Solution s;
    auto res = s.generate(5);
    for(auto& i: res)
    {
	for(int& n: i)
	{
	    cout << n << " ";
	}
	cout << endl;
    }
    return 0;
}
