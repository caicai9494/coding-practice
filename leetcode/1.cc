#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
	unordered_map<int,int> dict;
	for(unsigned int i = 0; i < numbers.size(); i++)
	{
	    if(dict.find(numbers[i]) == dict.end())
		dict[target - numbers[i]] = i;
	    else return {dict[numbers[i]]+1, i+1};
	}
	return {};
    }
};

