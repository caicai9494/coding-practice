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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool iless(const Interval& lhs, const Interval& rhs)
{
    return lhs.start == rhs.start ? lhs.start < rhs.start :
                                    lhs.end > rhs.end;
}

class Solution {
  public:
    vector<Interval> merge(vector<Interval>& intervals) 
    {
	vector<Interval> ret;
	if (intervals.empty()) {
	    return ret;
	}

	sort(intervals.begin(), intervals.end(), iless);

	ret.push_back(intervals[0]);
	for (size_t i = 1; i != intervals.size(); ++i) {
	    auto top = ret.back();
	    if (top.end >= intervals[i].end) {
		ret.pop_back();
		ret.push_back({top.start, max(top.end, intervals[i].end)});
	    }
	    else if (top.end >= intervals[i].end) {
		// do nothing
	    }
	    else { // no interval
		intervals.push_back(intervals[i]);
	    }
	}
	return ret;
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
