#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>


using namespace std;
class Solution {
public:
    bool isValid(string s) {

	if(s.emtpy() || s.length() % 2 != 0)
	    return false;

	stack<char> container;


	for(unsigned int i = 0; i < s.length(); i++)
	{
	    if(s[i] == '(' || s[i] == '[' || s[i] == '{')
		container.push(s[i]);
	    else// ) ] }
	    {
		if(container.empty())
		    return false;

		char c = container.top();
		if(c == '(' && s[i] == ')')
		    container.pop();
		else if(c == '[' && s[i] == ']')
		    container.pop();
		else if(c == '{' && s[i] == '}')
		    container.pop();
		else return false;
	    }
	}
        if(container.empty())
	    return true;

	else return false;

    }
};
int main()
{
    return 0;
}
