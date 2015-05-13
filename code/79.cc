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
	int R, C;
	bool exist(vector<vector<char>>& board, string word) {
	    R = board.size();
	    C = board[0].size();

	    for(size_t i = 0; i < R; ++i) {
		for(size_t j = 0; j < C; ++j) {
		    if(backtract(board, word, 0, i, j)) 
			return true;
		}
	    }
	    return false;
	}

	bool backtract(vector<vector<char>>& board, string &word, size_t pos, size_t i, size_t j) {
	    if(i < 0 || j < 0 || i >= R || j >= C ||  board[i][j] == '\0' || board[i][j] != word[pos]) return false;
	    if(pos == word.size()) return true;

	    char t = board[i][j];
	    board[i][j] = '\0';

	    if(
		backtract(board, word, pos+1, i, j+1) || 
		backtract(board, word, pos+1, i, j-1) ||
		backtract(board, word, pos+1, i+1, j) ||
		backtract(board, word, pos+1, i-1, j))
		return true;

	    board[i][j] = t;
	    return false;
	}

};
int main()
{
    Solution s;

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << (s.exist({{aaaaa", "aaaaa", "aaaaa", "aaaaa", "aaaab"}, string("aaaaaaaaaaaaaaaaaaa"))) << endl;
    return 0;
}
