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
	string addBinary(string a, string b) {
	    string ret;

	    int c = 0, i = a.size() - 1, j = b.size() - 1;
	    while(i >= 0 || j >= 0 || c == 1) {
		c += i >= 0 ? a[i--]-'0' : 0; 
		c += j >= 0 ? b[j--]-'0' : 0; 
		ret = char(c % 2 + '0') + ret;
		c /= 2;
	    }
	    return ret;
	}

};
int main()
{
    Solution s;
    string a = "11";
    string b = "1";
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    cout << s.addBinary(a,b) << endl;
    return 0;
}
