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
	void merge(int A[], int m, int B[], int n)
	{
	    while(m && n)
	    {
		if(A[m-1] > B[n-1])
		    A[n+m-1] = A[m-1], m--;
		else 
		    A[n+m-1] = B[n-1], n--;
	    }
	    while(n)
		A[n-1] = B[n-1], n--;
	}

};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    cout << s. << endl;
    return 0;
}
