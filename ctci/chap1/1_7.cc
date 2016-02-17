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

typedef uint32_t i32;
typedef std::vector<i32> Ivec;
typedef std::vector<Ivec> Matrix;

std::ostream& operator<< (std::ostream& stream, const Matrix& matrix)
{
    for (size_t i = 0; i != matrix.size(); ++i) {
	stream << matrix[i];
    }
}

void setZero(Matrix& mtx);

int main()
{
    Matrix mtx;
    Ivec row1 = {0,2,3};
    Ivec row2 = {4,0,6};
    Ivec row3 = {7,8,9};
    mtx.push_back(row1);
    mtx.push_back(row2);
    mtx.push_back(row3);

    setZero(mtx);
    DBG(mtx);
    //ASSERT_EQ(1, 1);
    //ASSERT_TRUE("123" == "1231");

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}

void setZero(Matrix& mtx)
{
    size_t sz = mtx.size();
    Ivec zeroRow(sz, 1);
    Ivec zeroCol(sz, 1);

    DBG(zeroRow);

    for (size_t i = 0; i != sz; ++i) {
	for (size_t j = 0; j != sz; ++j) {
	    if (mtx[i][j] == 0) {
		zeroRow[i] = zeroCol[j] = 0;
	    }
	}
    }

    for (size_t i = 0; i != sz; ++i) {
	if (zeroRow[i] == 0) {
	    for (size_t j = 0; j != sz; ++j) {
		mtx[i][j] = 0;
	    }
	}
	if (zeroCol[i] == 0) {
	    for (size_t j = 0; j != sz; ++j) {
		mtx[j][i] = 0;
	    }
	}
    }
}
