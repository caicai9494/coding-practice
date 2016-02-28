#ifndef LZ_TEST_H
#define LZ_TEST_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>

template <typename T>
void DBG_(const T& t) 
{
    std::cout << t;
}

template <typename T>
std::ostream& operator<< (std::ostream& stream, const std::vector<T>& vec) 
{
    for (size_t i = 0; i != vec.size(); ++i) {
	stream <<  vec[i] << " ";
    }
    stream << '\n';
}

template <typename T>
std::ostream& operator<< (std::ostream& stream, const std::list<T>& list) 
{
    for (auto i = list.begin(); i != list.end(); ++i) {
	stream <<  *i << " ";
    }
    stream << '\n';
}

#define DBG(var) \
    do {\
	std::cout << "[" #var ": \n";\
	DBG_(var);\
	std::cout << "]\n"; \
    } while(0)\

#define ASSERT_EQ(lhs, rhs) \
    if (lhs != rhs) { \
	printf("Assertion Fail at %s:line %d\n", __FILE__, __LINE__); \
	printf(#lhs " != " #rhs "\n"); \
	DBG(lhs);\
	DBG(rhs);\
	exit(EXIT_FAILURE); \
    } \

#define ASSERT_TRUE(condition) \
    if (!(condition)) { \
	printf("Assertion Fail at %s:line %d\n", __FILE__, __LINE__); \
	printf(#condition "\n"); \
	exit(EXIT_FAILURE); \
    } \

#endif
