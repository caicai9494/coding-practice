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
	const size_t NO = 1000;
	vector<vector<string>> ret;
	int totalNQueens(int n) {
	    vector<size_t> position(n,NO);
	    vector<string> place;
	    subroutine(0, n, position, place);
	    return ret.size();
	}

	void subroutine(size_t index, size_t n, vector<size_t>& pos, vector<string>& place) {
	    if(index == n) ret.push_back(place);
	    else {
		vector<int> nthQueen(n,1);

		//i -> col
		//index -> row
		for(size_t i = 0; i < n; i++) { //check previous queen
		    //posible positions of nth Queen
		    if(pos[i] != NO) {
			nthQueen[pos[i]] = 0; 

			if(pos[i]+index-i < n)
			    nthQueen[pos[i]+index-i] = 0;

			if(pos[i]-index+i >= 0 && pos[i]-index+i < n)
			    nthQueen[pos[i]-index+i] = 0;

		    }
		}

		for(size_t i = 0; i < nthQueen.size(); ++i) {

		    if(nthQueen[i] != 0) {
			string nthMap(n,'.');
			nthMap[i] = 'Q';
			pos[index] = i;
			//modify pos
			//make string;
			place.push_back(nthMap);
			subroutine(index+1, n, pos, place);
			place.pop_back();
			//undo modify pos
			pos[index] = NO;
		    }

		}
	    }
	}

};

    void print(vector<vector<string>>& result) {
	for(auto& v : result) {
	    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
	    cout << endl;
	}
    }
int main()
{
    Solution s;
    auto ret = s.solveNQueens(5);
    print(ret);

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
//    cout << s. << endl;
    return 0;
}
