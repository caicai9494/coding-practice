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
	vector<vector<int> >result;
	vector<vector<int> > subsets(vector<int> &S)
	{
	    vector<int> place;
	    sort(S.begin(), S.end());
	    for(int i = 0; i < S.size(); i++)
	        sub(S, i, 0, place);

	    return result;
	}
	void sub(vector<int> &S, int k, int index,  vector<int> &place)
	{
	    if(index == 0)
	        result.push_back(place);

	    for(int i = k; i < S.size(); i++)
	    {
		place.push_back(S[i]);
		sub(S, i, k + 1, place);
		place.pop_back();
	    }
	}

};

