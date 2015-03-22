#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {

	int i = 0, j = 0;
	while(j < n-1)
	{
	    while(A[j] == A[j+1])
		j++;

	    if(i != j)
	        A[i++] = A[j++];
	    else
		i++, j++;
	}
	return i;
	/*
	int count = n;
	int i;
	for(i = n - 1; i >= 1; i--)
	{
	    int j = i;
	    while(j >= 1 && A[j] == A[j-1])
		j--;
	    if(j != i)
	    {
		int offset = i - j;
		count -= offset;
		for(int k = j; k < count; k++)
		{
		    A[k] = A[k+offset];
		}
	    }
	    i = j;
	}

	return count;
	*/
    }
};
int main()
{
    Solution s;
    int p = 7;
    int A[] = {-1,0,0,0,0, 3, 3};
    //int A[] = {1,1,2};
    //int A[] = {1,1,2,2};
    //int A[] = {1,1,2,2,3};
    cout << s.removeDuplicates(A, p) << endl;
    cout << endl;
    for(int& a : A)
	cout << a << endl;
    return 0;
}
