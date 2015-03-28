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
	/*
	//vector<vector<int> >steps;
	int count = 0;
	//void rec(int n, vector<int> holder)
	void rec(int n)
	{
	    if(n == 0)
		count++;
		//steps.push_back(holder);
	    else
	    {
		if(n - 1 >= 0)
		{
		    //holder.push_back(1);
		    rec(n - 1);
		}
		if(n - 2 >= 0)
		{
		    //holder.push_back(2);
		    rec(n - 2);
		    //holder.pop_back();
		}
	    }
	}
	*/

	int climbStairs(int n)
	{
	    int first = 1;
	    int second = 0;
	    int count = 0;

	    for(int i = 1; i <= n; i++)
	    {
		count = first + second;
		second = first;
		first = count;
	    }
	    return count;
	}

};
int main()
{
    Solution s;
    //s.climbStairs(5, vector<int>());
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    /*
    for(auto& v: s.steps)
    {
	for(int& i: v)
	    cout << i << " ";
	cout << endl;
    }
    */
    cout << s.climbStairs(45)<<endl;
    return 0;
}
