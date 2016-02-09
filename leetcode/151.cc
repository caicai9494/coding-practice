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
	void reverseWords(string &s)
	{
	    size_t count = 0;
	    for(size_t j = 0; j < s.length(); j++)
	    {
		if(s[j] != ' ' || (j > 0 && s[j-1] != ' '))
		    s[count++] = s[j];
	    }
	    if(s[count-1] == ' ') count--;
	    s.resize(count);
	    if(count == 0) 
		return;

	    reverse(s.begin(), s.end());

	    size_t l,r,pos;
	    l = pos = 0;
	    while(1)
	    {
		l = pos;
		for(r = pos; r < count && s[r] != ' '; r++);
		r--;
		pos = r;

		while(l < r)
		    swap(s[r--], s[l++]);

		if(pos == count) break;
		else pos+=2;
	    }
	}

};
int main()
{
    Solution s;
    string str = "a";
    s.reverseWords(str);
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    cout << str << endl;
    return 0;
}
