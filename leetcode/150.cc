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
	bool isOperator(const string &s) {
	    if(s.length() != 1) return false; 
	    if(s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/') return true;
	    else return false;
	}
	int evalRPN(vector<string>& tokens) {
	    stack<string> cstack;

	    for(unsigned int i = 0; i < tokens.size(); i++) {
		if((!isOperator(tokens[i]))) {
		    cstack.push(tokens[i]);
		} else {
		    string a,b;
		    int aa, bb;
		    a = cstack.top();
		    cstack.pop();
		    b = cstack.top();
		    cstack.pop();

		    aa = stoi(a);
		    bb = stoi(b);

		    if(tokens[i][0] == '+') {
			bb += aa;
		    } else if(tokens[i][0] == '-') {
			bb -= aa;
		    } else if(tokens[i][0] == '*') {
			bb *= aa;
		    } else {
			bb /= aa;
		    }

		    b = to_string(bb);
		    cstack.push(b);
		}
	    }

	    return stoi(cstack.top());

	}

};
