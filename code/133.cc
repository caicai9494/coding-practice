#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>
#include <set>
#include <unordered_map>

using namespace std;
class Solution
{
    public:

	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	    if(!node) return node;
	    if(hash.find(node) == hash.end()) {
		hash[node] = new UndirectedGraphNode(node->label);
		for(auto& nn : node->neighbors) {
		    hash[node]->neighbors.push_back(cloneGraph(nn));
		}
	    }
	    return hash[node];
	}
};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    cout << s. << endl;
    return 0;
}
