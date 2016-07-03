#include <algorithm>
#include <cassert>
#include <limits>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "lz_error.h"

using namespace std;

class TicTacToe {

public:
  /** Initialize your data structure here. */
  typedef vector<pair<int/*player*/, int/*count*/>> States;

  TicTacToe(int n) : 
      d_rows(n, make_pair(-1,0)),
      d_cols(n, make_pair(-1,0)),
      d_diag(2, make_pair(-1,0)),
      d_n(n) {}

  void setStates(States* state, int pos, int player)
  {
      States& sref = *state;
      if (sref[pos].first == -1) {
	  sref[pos] = make_pair(player, 1);
      } 
      else if (sref[pos].first == player) {
	  sref[pos].second++;
      }
      else {
	  sref[pos].second = -1;
      }
  }

  bool win(States* state, int pos, int player) const
  {
      States& sref = *state;
      return 
	     sref[pos].first == player &&
	     sref[pos].second == d_n;
  }


  int move(int row, int col, int player) 
  {
      setStates(&d_rows, row, player);
      if (win(&d_rows, row, player)) {
	  return player;
      }

      setStates(&d_cols, col, player);
      if (win(&d_cols, col, player)) {
	  return player;
      }

      if (row == col) {
	  setStates(&d_diag, 0, player);
	  if (win(&d_diag, 0, player)) {
	      return player;
	  }
      }

      if (row == d_n - col - 1) {
	  setStates(&d_diag, 1, player);
	  if (win(&d_diag, 1, player)) {
	      return player;
	  }
      }

      return 0;
  }

  States d_rows;
  States d_cols;
  States d_diag;
  int d_n;
};

int main() {
  // int A[] = {5, 7, 7, 8, 8, 10};
  // vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
  // cout << s. << endl;
  return 0;
}
