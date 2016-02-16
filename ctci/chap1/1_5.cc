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

void replaceSpaces(std::string* output, 
	           const std::string& input, 
		   const std::string& pattern);

int main()
{
    std::string ret;
    const std::string pattern = "%20";
    const std::string input = "lala lfdf fd ";
    const std::string answer = "lala%20lfdf%20fd%20";
    DBG(answer);
    replaceSpaces(&ret, input, pattern);
    ASSERT_EQ(ret, answer);


    const std::string input2;
    replaceSpaces(&ret, input2, pattern);
    ASSERT_EQ(ret, input2);

    const std::string input3 = "a";
    replaceSpaces(&ret, input3, pattern);
    ASSERT_EQ(ret, input3);

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}

void replaceSpaces(std::string* output, 
	           const std::string& input, 
		   const std::string& pattern)
{
    assert(NULL != output);
    output->clear();

    int count = 0;
    for (auto i = input.begin(); i != input.end(); ++i) {
	if (*i == ' ') {
	    ++count;
	}
    }

    output->reserve(input.size() + count * pattern.size() - count);

    for (auto i = input.begin(); i != input.end(); ++i) {
	if (*i == ' ') {
	    output->append(pattern);
	}
	else {
	    output->push_back(*i);
	}
    }

}
