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

bool anagramSort(const std::string& lhs, 
                 const std::string& rhs);

bool anagramHash(const std::string& lhs, 
                 const std::string& rhs);
int main()
{
    //ASSERT_EQ(1, 1);
    ASSERT_EQ(anagramSort("abc", "cba"), true);
    ASSERT_EQ(anagramSort("aabc", "cba"), false);
    ASSERT_EQ(anagramSort("aabc", "acba"), true);

    ASSERT_EQ(anagramHash("abc", "cba"), true);
    ASSERT_EQ(anagramHash("aabc", "cba"), false);
    ASSERT_EQ(anagramHash("aabc", "caba"), true);
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}

bool anagramSort(const std::string& lhs, 
                 const std::string& rhs)
{
    std::string lhsCopy = lhs;
    std::sort(lhsCopy.begin(), lhsCopy.end());
    std::string rhsCopy = rhs;
    std::sort(rhsCopy.begin(), rhsCopy.end());
    return lhsCopy == rhsCopy;
}

bool anagramHash(const std::string& lhs, 
                 const std::string& rhs)
{
    if (lhs.size() != rhs.size()) {
	return false;
    }

    std::unordered_map<char, int>  hash;
    for (auto i = lhs.begin(); i != lhs.end(); ++i) {
	auto ret = hash.insert(std::make_pair(*i, 1));
	if (!ret.second) {
	    ++(ret.first->second);
	} 
    }

    for (auto i = rhs.begin(); i != rhs.end(); ++i) {
	auto ret = hash.find(*i);
	if (ret == hash.end() || ret->second == 0) {
	    return false;
	}
	else {
	    --(ret->second);
	}
    }
    return true;
}
