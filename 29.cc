#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;
class Solution {
public:
    int mysign(int v)
    {
	return v > 0 ? 1 : -1;
    }

    int divide(int dividend, int divisor)
    {
	
	int sign = 1;
	if(mysign(divisor) * mysign(dividend) < 0)
	    sign = -1;

	dividend = abs(dividend);
	divisor = abs(divisor);
	if(divisor < 0 && dividend < 0)
	    return 1;
	else if(dividend < 0)
	{
	    if(divisor != 1)
	        return sign*(rec(2, divisor, divisor, 1) + rec(numeric_limits<int>::max(), divisor, divisor, 1));
	    else 
		return numeric_limits<int>::max();
	}
	else if(divisor < 0)
	    return 0;


	/*
	if(divisor == -1 && dividend == numeric_limits<int>::min())
	    return numeric_limits<int>::max();
	if(divisor == 0 || divisor == numeric_limits<int>::min())
	    return numeric_limits<int>::max();
	if(dividend == 0)
	    return 0;


	if(divisor == 1 && dividend == numeric_limits<int>::min())
	    return numeric_limits<int>::min();
	    */
	/*
	if(mysign(divisor) * mysign(dividend) < 0)
	{
	    if(dividend < 0) divisor = - divisor;
	    else dividend = -dividend;
	}
	*/
	    //return numeric_limits<int>::max();
	//cout << dividend << endl;
	//cout << divisor << endl;

	if(dividend < divisor) return 0;
	return sign * rec(dividend, divisor, divisor, 1);
    }

    int rec(int dividend, int divisor, int holder, int place)
    {
	//cout << place << endl;
	if(dividend < divisor) return place - 1;
	if(dividend <= holder)
	    return place;

	if(dividend - holder - holder < 0)
	    return place + rec(dividend - holder, divisor, divisor, 1);
	else
	    return rec(dividend, divisor , holder + holder, place + place);
    }

};
int main()
{
    Solution s;

    //cout << s.divide(-20, 4) << endl;
    cout << s.divide(-1010369383, numeric_limits<int>::min()) << endl;
    //cout << s.control(numeric_limits<int>::max(), 1) << endl;
    return 0;
}
