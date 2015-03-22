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
	    /*
	    int num = 0;
	    for(int i = 0; i < n; i++)
		num ^= A[i];
	    return num;
	    */
	    map<int,int> container;
	    for(int i = 0; i < n; i++)
	    {
		auto ret = container.find(A[i]);
		if(ret == container.end())
		    container.insert(make_pair(A[i], 0));
		else
		{
		    if(ret->second == 1)
		        container.erase(A[i]);
		    else
			ret->second ++;
		}
	    }
	    return container.begin()->first;
	}

};
int main()
{
    Solution s;
    int A[] = {1,1,1, 2, 2,2,3};
    cout << s.singleNumber(A,7) << endl;
    return 0;
}
