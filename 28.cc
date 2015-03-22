#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>
#include <cstring>

using namespace std;
class Solution {
public:
    int strStr(char* haystack, char* needle) {
	if(haystack == NULL || needle == NULL)
	    return -1;

	char* ptrH;
	char* ptrN;

	if(*needle == '\0')
	    return 0;

	for(ptrH = haystack, ptrN = needle; ; ptrH++)
	{
	    if(*ptrH == *ptrN)
	    {
	        char* h = ptrH;
	        char* n = ptrN;

		while(*n != '\0' && *h != '\0' && *n == *h) 
		    n++, h++;
		if(*n == '\0')
		    return ptrH - haystack;
		else if(*h == '\0')
		    return -1;
		else continue;
	    }

	    if(*ptrH == '\0') return -1;
	    
	}
	return - 1;
    }
};
int main()
{
    Solution s;
    cout << s.strStr("aabaaaababaababaa", "bbbb") << endl;;
    //cout << s.strStr("", "") << endl;;
    return 0;
}
