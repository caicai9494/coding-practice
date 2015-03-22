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
	void sortColors(int A[], int n)
	{
	    int red, white, blue;
	    red = white = blue = 0;
	    for(int i = 0; i < n; i++)
	    {
		switch(A[i])
		{
		    case 0:
			red++;
			break;
		    case 1:
			white++;
			break;
		    case 2:
			blue++;
			break;
		    default:
			break;
		}
	    }
	    for(int i = 0; i < n; i++)
	    {
		while(red--)
		    A[i++] = 0;
		while(white--)
		    A[i++] = 1;
		while(blue--)
		    A[i++] = 2;
	    }
	}

};
int main()
{
    Solution s;
    int A[] = {0, 1, 1, 0, 2, 1};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    s.sortColors(A,6);
    for(int& i: A)
	cout << i << endl;
    return 0;
}
