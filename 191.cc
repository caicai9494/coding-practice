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
	int hammingWeight(uint32_t n)
	{
	    int count = 0;
	    while(n != 0)
	    {
		if(n % 2 == 1)
		    count++;
		n >>= 1;
	    }

	    return count;
	}

};
int main()
{
    Solution s;
    cout << s.hammingWeight(00000000000000000000000000001011) << endl;
    return 0;
}
