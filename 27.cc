#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>

using namespace std;
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
	int i = 0, j = 0;
	while(j < n)
	{
	    while(j < n && A[j] == elem)
		j++;
	    if(j >= n)
		break;

	    if(i != j)
	        A[i++] = A[j++];
	    else
		i++, j++;
	}
	if(!i)
	    return;
	return i;
        
    }
};
int main()
{
    Solution s;
    int p = 5;
    //int A[] = {-1,0,0,0,0, 3, 3};
    //int A[] = {1,1,2};
    //int A[] = {1,1,2,2};
    int A[] = {1,1,2,2,3};
    cout << s.removeElement(A, p, 2) << endl;
    cout << endl;
    for(int& a : A)
	cout << a << endl;
    return 0;
}
