#include <list_double.h> 
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

int main()
{
    LZ::List<int> list;
    ASSERT_EQ(list.empty(), true);

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);


    ASSERT_EQ(*list.begin(), 3);

    list.pop_front();
    ASSERT_EQ(*list.begin(), 2);

    list.push_back(5);
    list.pop_back();

    for (auto itr = list.begin(); itr != list.end(); ++itr) {
	std::cout << *itr << '\n';
    }

    //list.insert(1);
    //ASSERT_EQ(1, 1);
    //ASSERT_TRUE("123" == "1231");

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
