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
	int uniquePaths(int m, int n)
	{
	    const int X = m;
	    const int Y = n;
	    int grid[X][Y];

	    for(int i = 0; i < X; i++)
		grid[i][0] = 1;
	    for(int i = 0; i < Y; i++)
		grid[0][i] = 1;

	    for(int i = 1; i < X; i++)
	    {
		for(int j = 1; j < Y; j++)
		{
	            grid[i][j] = grid[i-1][j] + grid[i][j-1];
		}
	    }

	    return grid[m-1][n-1];

	}


};
int main()
{
    Solution s;
    cout << s.uniquePaths(23, 12) << endl;
    return 0;
}
