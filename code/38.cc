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
    /*
    void generate(const string &str, string &res, int place) 
    {
	unsigned int len = str.length();
	if(place == len)
	    break;

	int i = place;
	if(str[place] = '1')
	    res += '11'

    }
    */
    string countAndSay(int n) {

       string result = "1";
       if(n > 1)
       {
	   for(int i = 1; i < n; i++)
	   {
	       string temp;
	       int len = result.length();
	       for(int i = 0; i < len; i++)
	       {
		   char rep = result[i];
		   int count = 1;
		   int j = i;
		   while(j < len-1 &&  result[j] == result[j + 1])
		       count++, i++, j++;
		   temp += (count + '0');
		   temp += rep;
	       }
	       result = temp;
	   }
       }

       return result;
    }
};
int main()
{
    Solution s;
    for(int i = 0; i < 10; i++)
    cout << s.countAndSay(i) << endl;
    return 0;
}
