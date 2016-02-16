#include <algorithm>
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

#include <lz_test.h>

bool isUniqueHash(const std::string& str);
bool isUniqueNoHash(const std::string& str);

int main()
{
    ASSERT_TRUE(isUniqueHash("123"));
    ASSERT_TRUE(isUniqueHash(""));
    ASSERT_TRUE(!isUniqueHash("aaa"));
    ASSERT_TRUE(!isUniqueHash("123aaa"));
    ASSERT_TRUE(!isUniqueHash("  123aaa"));

    ASSERT_TRUE(isUniqueNoHash("123"));
    ASSERT_TRUE(isUniqueNoHash(""));
    ASSERT_TRUE(!isUniqueNoHash("aaa"));
    ASSERT_TRUE(!isUniqueNoHash("123aaa"));
    ASSERT_TRUE(!isUniqueNoHash("  123aaa"));

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}

bool isUniqueHash(const std::string& str)
{
    std::unordered_set<char> str_hash;
    for (auto it = str.begin(); 
	 it != str.end(); ++it) {
	auto ret = str_hash.insert(*it);
	if (!ret.second) {
	    return false;
	} 
    }
    return true;
}

bool isUniqueNoHash(const std::string& str)
{
    std::string str_copy = str;
    std::sort(str_copy.begin(), str_copy.end());

    for (auto it = str_copy.begin(); 
	 it != str_copy.end(); ++it) {
	auto it_copy = it;
	++it_copy;
	if (it_copy != str_copy.end() && (*it == *it_copy)) {
	    return false;
	}
    }
    return true;
}
