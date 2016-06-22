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
    int compareVersion(const string& version1, const string& version2) 
    {
	size_t it1 = 0;
	size_t size1 = version1.size();
	size_t it2 = 0;
	size_t size2 = version2.size();

	int v1 = 0;
	int v2 = 0;

	while (it1 != size1 || it2 != size2) {
	    while (it1 != size1 && '.' != version1[it1]) {
		v1 = 10 * v1 + version1[it1] - '0';
		++it1;
	    }
	    while (it2 != size2 && '.' != version2[it2]) {
		v2 = 10 * v2 + version2[it2] - '0';
		++it2;
	    }

	    if (v1 < v2) { return -1; }
	    else if (v1 > v2) { return 1; }
	    else {
		v1 = 0;
		v2 = 0;
		it1++;
		it2++;
	    }
	}
	return 0;
    }
};

int main()
{
    Solution s;
    DBG(s.compareVersion("1.1", "1.10"));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
