#include <list_cursor.h> 
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

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    ASSERT_EQ(list.getNext()->data(), 1);
    ASSERT_EQ(list.getNext()->data(), 2);
    ASSERT_EQ(list.getNext()->data(), 3);
    ASSERT_EQ(list.getNext() == nullptr, true);
    ASSERT_EQ(list.getNext()->data(), 1);

    list.removeCurrent();

    ASSERT_EQ(list.getNext()->data(), 3);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.rewind();
    for (auto itr = list.getNext(); 
	 itr != list.getEnd(); itr = list.getNext()) {
	std::cout << itr->data() << '\n';
    }

    LZ::List<int> list2;
    list2.push_back(5);
    list2.push_back(6);
    list2.push_back(7);

    list.merge(list2);

    std::cout << "after merge\n";

    list.rewind();
    for (auto itr = list.getNext(); 
	 itr != list.getEnd(); itr = list.getNext()) {
	std::cout << itr->data() << '\n';
    }

    ASSERT_EQ(list2.empty(), true);




    //list.insert(1);
    //ASSERT_EQ(1, 1);
    //ASSERT_TRUE("123" == "1231");

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
