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
	int singleNumber(int A[], int n)
	{
	    int num = 0;
	    for(int i = 0; i < n; i++)
		num ^= A[i];
	    return num;
	    /*
	    set<int> container;
	    for(int i = 0; i < n; i++)
	    {
		if(container.find(A[i]) == container.end())
		    container.insert(A[i]);
		else
		    container.erase(A[i]);
	    }
	    return *container.begin();
	    */
	}

};
int main()
{
    Solution s;
    int A[] = {1,1,2,2,3};
    cout << s.singleNumber(A,5) << endl;
    return 0;
}
