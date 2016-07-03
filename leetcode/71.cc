#include <algorithm>
#include <cassert>
#include <limits>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#include "lz_error.h"

using namespace std;

class Solution {
  public:
    string simplifyPath(string path) 
    {
	vector<string> stk;
	string tmp;
	stringstream stream;
	stream << path;
	while (getline(stream, tmp, '/')) {

	    if (tmp == "." || tmp == "") { } //do nothing
	    else if (tmp == "..") { 
		if (!stk.empty()) {
		    stk.pop_back(); 
		}
	    }
	    else {
		stk.push_back(tmp);
	    }

	}

	string ret = "/";
	for (string& str : stk) {
	    ret += str + "/";
	}

	return ret;
    }
    void foo()
    {
	stringstream ss;
	ss << "this is haaa";
	string token;
	while (getline(ss, token, ' ')) {
	    DBG(token);
	}
    }
};

int main()
{
    Solution s;
    DBG(s.simplifyPath("/home/a/"));
    DBG(s.simplifyPath("/home/../a/"));
    DBG(s.simplifyPath("/home/./../a/"));
    DBG(s.simplifyPath("/a/./b/../../c/"));
    DBG(s.simplifyPath("/home//a/"));
    DBG(s.simplifyPath("//"));
    DBG(s.simplifyPath("/../"));
    DBG(s.simplifyPath("/root/../../"));
    DBG(s.simplifyPath("/..."));

    //s.foo();
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
