#include <algorithm>
#include <assert.h>
#include <bitset>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <tool/lz_test.h>

typedef std::list<int> List;
typedef List::const_iterator It;

void addLists(List& ret, const List& lhs, const List& rhs);
    // Add 'lhs' to 'rhs' and populate 'ret' with the result.
    // Anything stored in 'ret' prior passing into the function
    // will be lost
void addLists_(List& ret, List& lhs, List& rhs, int carry);

int main()
{
    List ret;

    const List LHS = {3, 1, 5};
    const List RHS = {5, 9, 2};
    addLists(ret, LHS, RHS);
    DBG(ret);

    const List LHS2 = {5};
    addLists(ret, LHS2, RHS);
    DBG(ret);

    const List LHS3 = {5, 0, 8};
    addLists(ret, LHS3, RHS);
    DBG(ret);

    const List LHS4;
    const List RHS2;
    addLists(ret, LHS4, RHS2);
    DBG(ret);
    //ASSERT_EQ(1, 1);
    //ASSERT_TRUE("123" == "1231");

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}

void addLists(List& ret, const List& lhs, const List& rhs)
{
    ret.clear();

    List lhsCopy = lhs;
    List rhsCopy = rhs;
    addLists_(ret, lhsCopy, rhsCopy, 0);
}

void addLists_(List& ret, List& lhs, List& rhs, int carry)
{
    if (lhs.empty() && rhs.empty()) {
	if (carry > 0) {
	    ret.push_back(carry);
	}
	return;
    }

    int val = carry;

    int lval = 0;
    if (lhs.empty()) {
        lval = 0;
    } else {
	lval = lhs.front();
	lhs.pop_front();
    }

    int rval = 0;
    if (rhs.empty()) {
        rval = 0;
    } else {
	rval = rhs.front();
	rhs.pop_front();
    }

    val += lval;
    val += rval;

    carry = (val > 9) ? 1 : 0;
    ret.push_back(val % 10);

    addLists_(ret, lhs, rhs, carry);
}
