#include <algorithm>
#include <assert.h>
#include <bitset>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <tool/lz_test.h>

bool isRotation(const std::string& origin, const std::string& totest);

int main()
{
    const std::string ORIGIN = "waterbottle";
    const std::string ROTATE = "erbottlewat";
    ASSERT_EQ(isRotation(ORIGIN, ROTATE), true);

    const std::string ROTATE2 = "rbottlewat";
    ASSERT_EQ(isRotation(ORIGIN, ROTATE2), false);

    const std::string ROTATE3 = "rebottlewat";
    ASSERT_EQ(isRotation(ORIGIN, ROTATE3), false);
    //ASSERT_TRUE("123" == "1231");

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}

bool isRotation(const std::string& origin, const std::string& totest)
{
    if (origin.size() != totest.size()) {
	return false;
    }

    std::string copy = totest + totest;
    if (std::string::npos == copy.find(origin)) {
	return false;
    }
    return true;
}
