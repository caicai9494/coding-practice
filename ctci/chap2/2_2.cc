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

int nthTilLast(const List& list, size_t nth); 
    // Return nth entry until the tail of the list.
    // If 'nth' is greater than the overall length, 
    // return -1. 

size_t nthTilLast_(int* val, const List& list, It cursor, size_t nth);

int main()
{
    List list = {1,2,3,4,5,6,7,8,9};
    const int ret = nthTilLast(list, -1); // overflow
    ASSERT_EQ(-1, ret);

    const int ret2 = nthTilLast(list, 0);
    ASSERT_EQ(9, ret2);

    const int ret3 = nthTilLast(list, 9);
    ASSERT_EQ(-1, ret3);

    const int ret4 = nthTilLast(list, 8);
    ASSERT_EQ(1, ret4);
    //ASSERT_TRUE("123" == "1231");

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}

size_t nthTilLast_(int* val, const List& list, It cursor, size_t nth)
{
    assert(val != NULL);

    if (cursor == list.end()) {
	return 0;
    }

    It copy = cursor;
    int len = nthTilLast_(val, list, ++cursor, nth);
    if (len == nth) {
	*val = *copy;
    }
    return len + 1;
}

int nthTilLast(const List& list, size_t nth)
{
    int val = 0;
    int ret = nthTilLast_(&val, list, list.begin(), nth);
    if (nth >= ret) {
	return -1;
    }
    return val;
}
