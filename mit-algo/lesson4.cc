#include <algorithm>
#include <cassert>
#include <functional>
#include <limits>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "lz_error.h"

using namespace std;

template<typename T>
class MaxHeap {
  public:
      void test()
      {
	  ASSERT_EQ(parent(5), 2);
	  ASSERT_EQ(leftChild(5), 10);
	  ASSERT_EQ(rightChild(5), 11);
      }

      void maxHeapify()
      {
	  for (size_t i = d_data.size() / 2 + 1; i != 0;) {
	      --i;
	      maxHeapifyImpl(i);
	  }
      }
  private:

      size_t leftChild(size_t i) const
      {
	  return 2 * i;
      }

      size_t rightChild(size_t i) const
      {
	  return 2 * i + 1;
      }

      size_t parent(size_t i) const
      {
	  return i / 2;
      }

      void maxHeapifyImpl(size_t i)
	  // assume only the 'i'-th item violate
	  // max heap 
      {
	  if (d_data.empty()) {
	      return;
	  }

      }

      std::vector<T> d_data;

};

int main()
{
    MaxHeap<int> mh;
    mh.test();

    if (std::greater<int>()(5, 2)) {
	std::cout << "yy\n";
    }
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
