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
	typedef unsigned int UINT;
	typedef struct Point
	{
	    UINT x;
	    UINT y;
	    Point(UINT a, UINT b): x(a), y(b){}
	}tPoint; 

	UINT ROW;
	UINT COL;

	set<UINT>row_set;
	set<UINT>col_set;

	void setZeroes(vector<vector<int> > &matrix)
	{
	    vector<tPoint> container;
	    ROW = matrix.size();
	    COL = matrix[0].size();

	    for(UINT i = 0; i < ROW; i++)
	    {
		for(UINT j = 0; j < COL; j++)
		{
		    if(col_set.find(j) != col_set.end())
			continue;
		    if(matrix[i][j] == 0)
		    {
			container.push_back(tPoint(i,j));
			row_set.insert(i);
			col_set.insert(j);
		    }
		}
	    }

	    /*
	    for(auto i = row_set.begin(); i != row_set.end(); i++)
		for(int& j:matrix[*i])
		    j = 0;
	    for(auto i = col_set.begin(); i != col_set.end(); i++)
		for(UINT j = 0; j < ROW; i++)
		    matrix[j][*i] = 0;
		    */
	    for(tPoint& point: container)
	    {
		for(int& i:matrix[point.x])
		    i = 0;
		for(UINT i = 0; i < ROW; i++)
		    matrix[i][point.y] = 0;
	    }
	}

};
int main()
{
    Solution s;
    vector<int> temp1 = {0,1};
    //vector<int> temp2 = {0,2,3};
    //vector<int> temp3 = {1,2,0};
    vector<vector<int> > container = {temp1};
    s.setZeroes(container);

    for(auto& c: container)
    {
	for(int& i: c)
	    cout << i << " ";
	cout << endl;
    }
    return 0;
}
