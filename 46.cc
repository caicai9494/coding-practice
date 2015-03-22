#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>

using namespace std;
class Solution {
public:
    vector<vector<int>> container;
    void generate(const vector<int> &num, vector<int> holder, unsigned int place, vector<bool>& visited)
    {
	unsigned int len = num.size();
	if(place == len)
	{
	    container.push_back(holder);
	    //for(unsigned int i = 0; i < len; i++)
		//visited[i] = false;
	    return;
	}

	for(unsigned int i = 0; i < len; i++)
	{
	    if(!visited[i])
	    {
		visited[i] = true;
	        holder.push_back(num[i]);
	        generate(num, holder, place + 1, visited);
	        holder.pop_back();
		visited[i] = false;
	    }
	} 
    }

    vector<vector<int> > permute(vector<int> &num) {
	vector<bool> visited(num.size(), false);
	generate(num, vector<int>(), 0, visited);
	return container;
    }
};
int main()
{
    Solution s;
    vector<int>num = {1, 2, 3, 4};
    auto res = s.permute(num);
    for(auto& s : res)
    {
        for(auto& p : s)
	cout << p << " ";
	cout << endl;
    }

    return 0;
}
