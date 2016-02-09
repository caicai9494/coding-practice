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

using namespace std;
class Solution
{
    public:
	unordered_map<int, RandomListNode*> hash;

	RandomListNode *copyRandomList(RandomListNode *head) {

	    if(!head) return head;
	    else {
		RandomListNode *node;

		if(hash.find(head->label) == hash.end()) {
		    hash[head->label] = new RandomListNode(head->label);
		} 
		node = hash[head->label];

		if(head->random) {
		    if(hash.find(head->random->label) == hash.end()) {
			hash[head->random->label] = new RandomListNode(head->random->label);
		    } 
		    node->random = hash[head->random->label];
		} else node->random = nullptr;

		node->next = copyRandomList(head->next);

		return node;
	    }

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
