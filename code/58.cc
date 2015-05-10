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
	int lengthOfLastWord(string s) {
	    int count = 0;
	    int i;
	    for(i = s.length() - 1; i >= 0 && s[i] == ' '; --i)
		;

	    for(; i >= 0; --i) {
		if(s[i] == ' ') return count;
		else ++count;
	    }
	    return count;
	}

};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    cout << s.lengthOfLastWord("hello world 111ii1") << endl;
    cout << s.lengthOfLastWord("hello ") << endl;
    return 0;
}
