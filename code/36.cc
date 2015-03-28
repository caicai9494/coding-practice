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
#include <cstring>

using namespace std;
class Solution
{
    public:
	bool checkRC(vector<vector<char> > &board, int i)
	{
	    int boardCheck[9];
	    memset(boardCheck, 0, sizeof(int) * 9);
		for(unsigned int r = 0; r < 9; r++)
		    if(board[i][r] != '.')
			boardCheck[board[i][r]-'1'] ++;

	    for(int j = 0; j < 9; j++)
		if(boardCheck[j] > 1) return false;
	    memset(boardCheck, 0, sizeof(int) * 9);

		for(unsigned int c = 0; c < 9; c++)
		    if(board[c][i] != '.')
			boardCheck[board[c][i]-'1'] ++;
		    

	    for(int j = 0; j < 9; j++)
		if(boardCheck[j] > 1) return false;
	    return true;
	}
	bool checkArea(vector<vector<char> > &board, int i, int j)
	{
	    int boardCheck[9];
	    memset(boardCheck, 0, sizeof(int) * 9);

	    for(int m = i; m < i + 3; m++)
	    {
		for(int n = j; n < j + 3; n++)
		{
		    if(board[m][n] != '.')
			boardCheck[board[m][n]-'1'] ++;
		}
	    }
	    for(int j = 0; j < 9; j++)
		if(boardCheck[j] > 1) return false;

	    return true;
	}

	bool isValidSudoku(vector<vector<char> > &board)
	{
	    for(int i = 0; i < 9; i++)
	    {
		if(!checkRC(board, i))
		    return false;
	    }

	    for(int m = 0; m < 9; m+=3)
	    {
		for(int n = 0; n < 9; n+=3)
		{
		    if(!checkArea(board, m, n))
			return false;
		}
	    }

	    return true;

	}

};
