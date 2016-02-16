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

#include <cstring>

#include <lz_test.h>

void reverse(char src[], size_t len);

int main()
{
    char array1[] = "abcde";
    reverse(array1, sizeof(array1) / sizeof(char));
    ASSERT_TRUE(strcmp(array1, "edcba") == 0);

    char array2[] = "";
    reverse(array2, sizeof(array2) / sizeof(char));
    ASSERT_TRUE(strcmp(array2, "") == 0);

    char array3[] = "a";
    reverse(array3, sizeof(array3) / sizeof(char));
    ASSERT_TRUE(strcmp(array3, "a") == 0);

    char array4[] = "abcd";
    reverse(array4, sizeof(array4) / sizeof(char));
    ASSERT_TRUE(strcmp(array4, "dcba") == 0);
    //ASSERT_EQ(1, 1);

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}

void reverse(char src[], size_t len)
{
    if (len <= 2) {
	return;
    }

    for (size_t i = len - 2, j = 0; j < i; --i, ++j) {
	char tmp = src[j];
	src[j] = src[i];
	src[i] = tmp;
    }
}
