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

	if(n == 0) return 0;

	int i, j = 0;
	bool isTwice = false;
	for(i = 1; i < n; i++)
	{
	    if(A[i] != A[i-1]) A[j+1] = A[i], j++, isTwice = false;
	    else if(A[i] == A[i-1] && !isTwice) isTwice = true, A[j+1] = A[i], j++;
	}
	
	return j+1;
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
