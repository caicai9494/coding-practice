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
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
	vector<vector<int>> copy(matrix);
	int row = matrix.size();
	int col = matrix[0].size();

	for(int i = 0; i < row; i++)
	    for(int j = 0; j < col; j++)
		copy[j][row-i-1] = matrix[i][j];
	return copy;
    }
};
int main()
{
    vector<int> temp1 = {1, 2, 3};
    vector<int> temp2 = {4, 5, 6};
    vector<int> temp3 = {7, 8, 9};
    vector<vector<int>> m = {temp1, temp2, temp3};

    Solution s;
    auto c = 
    return 0;
}
