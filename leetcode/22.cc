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
    vector<string> container;
    int left_para(const string &str)
    {
	int count = 0;
	for(unsigned int i = 0; i < str.length(); i++)
	{
	    if(str[i] == '(')
		count ++;
	}
	return count;
    }

    int close_para(const string &str)
    {
	stack<char> tempstack;
	int count = 0;
	for(unsigned int i = 0; i < str.length(); i++)
	{
	    if(str[i] == '(')
	 	tempstack.push(str[i]);
	    else
	    {
		tempstack.pop();
		count ++;
	    }
	}

	return count;
    }
    int open_para(const string &str)
    {
	stack<char> tempstack;
	for(unsigned int i = 0; i < str.length(); i++)
	{
	    if(str[i] == '(')
	 	tempstack.push(str[i]);
	    else
		tempstack.pop();
	}
	int count = 0;
	while(!tempstack.empty())
	{
	    count++;
	    tempstack.pop();
	}

	return count;
    }

    void generate(const int n, string holder, int place)
    {
	if(2*n == place)
	{
	    container.push_back(holder);
	    return;
	}

	//int closed = close_para(holder);
	int left_count = left_para(holder);
	int right_count = place - left_count;
	if(left_count == n)
	    generate(n, holder+')', place+1);
	else if(left_count >= right_count)
	{
	    generate(n, holder+'(', place+1);
	    generate(n, holder+')', place+1);
	}
    }

    vector<string> generateParenthesis(int n) {
	generate(n, "(", 1);
	return container;
    }
};
int main()
{
    Solution s;
    auto res = s.generateParenthesis(3);
    for(string &s: res)
	cout << s << endl;
    //string s = "(((";
    //cout << s.close_para("(");
    return 0;
}
