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
#include <cctype>

using namespace std;
class Solution
{
    public:
	bool isPalindrome(string s)
	{
	    auto it1 = s.begin(); 
	    auto it2 = s.end() - 1;

	    bool ret = true;
	    while(it1 < it2)
	    {
		if(!isalnum(*it1))
		{
		    it1++;
		    continue;
		}
		else if(!isalnum(*it2))
		{
		    it2--;
		    continue;
		}
		else if(tolower(*it1) == tolower(*it2))
		{
		    it1++, it2--;
		}
		else return false;
	    }
	    return ret;
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
