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

	uint32_t reverseBits(uint32_t n)
	{
	    uint32_t mask = 0x1;
	    uint32_t ret = 0;
	    for(int i = 0; i < 32; i++)
	    {
		if((n & mask) == 0)
		    ret = (ret << 1);
		else
		    ret = (ret << 1) + 1;

		n >>= 1;
	    }
	    return ret;
	}

};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    cout << s.reverseBits(43261596) << endl;
    return 0;
}
