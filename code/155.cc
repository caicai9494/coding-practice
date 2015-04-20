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
class MinStack
{
    public:


	void push(int x) {
	    vstack.push(x);

	    if(mstack.empty()) {
		mstack.push(x);
	    } else if(x <= mstack.top()) {
		    mstack.push(x);
	    } 
	}
	void pop() { 
	    if(vstack.top() == mstack.top())
	        mstack.pop();
	    vstack.pop();
	}
	int top() {
	    return vstack.top();
	}
	int getMin() {
	    return mstack.top();
	}
    private:
	stack<int> mstack;
	stack<int> vstack;
	    

};
