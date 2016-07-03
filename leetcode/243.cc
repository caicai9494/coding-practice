#include <algorithm>
#include <cassert>
#include <limits>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "lz_error.h"

using namespace std;

class Solution {
  public:
    int shortestDistance(const vector<string>& words, const string& word1, const string& word2) 
    {
	vector<int> pos1;
	vector<int> pos2;
	for (int i = 0; i < words.size(); ++i) {
	    if (words[i] == word1) {
		pos1.push_back(i);
	    }
	    else if (words[i] == word2) {
		pos2.push_back(i);
	    }
	}
	int mx = 99999;
	for (int i = 0; i < pos1.size(); ++i) {
	    for (int j = 0; j < pos2.size(); ++j) {
		if (abs(pos1[i] - pos2[j]) < mx) {
		    mx = abs(pos1[i] - pos2[j]);
		}
	    }
	}
	return mx;
    }
};

int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
