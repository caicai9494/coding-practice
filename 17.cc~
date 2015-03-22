#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {

	vector<int> result;

	multimap<int,int> container;
	for(unsigned int i = 0; i < numbers.size(); i++)
	    container.insert(make_pair(numbers[i], i+1));

	for(auto& p: container)
	{
	    int num = p.first;
	    auto res = container.find(target - num);

	    if(res != container.end())
	    {
	        if(p.second == res->second)
	        {
	            auto res2 = container.equal_range(p.first);
	            if(res2.first != res2.second)
	                {
	                    for(auto ptr = res2.first; ptr != res2.second; ptr++)
	                        result.push_back(ptr->second);
	                    sort(result.begin(), result.end());
	                    return result;
	                }
	        }
	        
	        else{
		    result.push_back(p.second);
		    result.push_back(res->second);
		    sort(result.begin(), result.end());
		    return result;
	        }
	    }
    }
    
    }
};

