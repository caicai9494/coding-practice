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

bool cmpr(const Interval& lhs, const Interval& rhs)
{
    return lhs.start < rhs.start;
}

class Solution {
  public:

    bool canAttendMeetings(vector<Interval>& intervals) 
    {
	sort(intervals.begin(), intervals.end(), cmpr);
	for (size_t i = 1; i < intervals.size(); ++i) {
	    if (intervals[i-1].end > intervals[i].start) {
		return false;
	    }
	}
	return true;
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
