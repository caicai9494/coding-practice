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
	int atoi(string str)
	{
	    if(str=="") return 0;
	    return stoi(str);
	}
	int stoi(string str)
	{
	    int i, sign, power, subsign;
	    double ret = 0.0, ret2 = 0.0;

	    for(i = 0; str[i] == 32; i++); //get rid of blacnks
	    sign = (str[i] == '-') ? -1 : 1;
	    if(str[i] == '+' || str[i] == '-') //get rid of sign 
		i++;

	    for(; str[i] <= '9' && str[i] >= '0'; i++) //get before decimal
		ret = ret * 10 + str[i] - '0';
	    if(ret > numeric_limits<int>::max() && sign > 0) return numeric_limits<int>::max(); //deal with overflow
	    if(ret-1 >= numeric_limits<int>::max() && sign < 0) return numeric_limits<int>::min();

	    if(str[i] == '.') i++; //get after dicimal
	    for(power = 0; str[i] <= '9' && str[i] >= '0'; i++)
		ret += (str[i] - '0') * pow(10, power - 1);

	    if(str[i] == 'e' || str[i] == 'E') i++; //get science sign
	    subsign = (str[i] == '-') ? -1 : 1;
	    if(str[i] == '+' || str[i] == '-') 
		i++;

	    for(power = 0; str[i] <= '9' && str[i] >= '0'; i++) //get science
		power = power * 10 + str[i] - '0';

	    ret2 = ret * pow((subsign == 1) ? 10 : 0.1, power);
	    if(ret2 > numeric_limits<int>::max())
	    {
		if(ret > numeric_limits<int>::max())
		    return numeric_limits<int>::max(); 
		else return sign * (int)rek;

	    }	//deal with overflow

	    return sign * (int)ret2;
	}

};
int main()
{
    cout << numeric_limits<int>::min() - 1<<endl;
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    char str[100];
    while(1)
    {
    scanf("%s", str);
    cout << s.stoi(str) << endl;
    }
    return 0;
}
