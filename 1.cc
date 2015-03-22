#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> container;
    map<char, string> phonekey;

    void initialize()
    {
	phonekey.insert(make_pair('2', "abc"));
	phonekey.insert(make_pair('3', "def"));
	phonekey.insert(make_pair('4', "ghi"));
	phonekey.insert(make_pair('5', "jkl"));
	phonekey.insert(make_pair('6', "mno"));
	phonekey.insert(make_pair('7', "pqrs"));
	phonekey.insert(make_pair('8', "tuv"));
	phonekey.insert(make_pair('9', "wxyz"));
    }

    void next_permutation(const string &digits, string holder, int place)
    {
	if(place == digits.length())
	{
	    container.push_back(holder);
	    return;
	}

	for(char& c: phonekey[digits[place]])
	{
	    holder += c;
	    next_permutation(digits, holder, place + 1);
	    holder.resize(place);
	}
    }

    vector<string> letterCombinations(string digits) {
	//vector<int> visited(26,0);
	//vector<string> resV;
	initialize();
	next_permutation(digits, "", 0);

	return container;
    }
};

int main()
{
    Solution s;
    auto res = s.letterCombinations("234");
    for(string &s : res)
	cout << s << endl;
    return 0;
}
