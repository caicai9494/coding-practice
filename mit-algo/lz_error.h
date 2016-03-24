#ifndef LZ_ERROR_H
#define LZ_ERROR_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <string>

template <typename T>
void DBG_(const T& t) 
{
    std::cout << t;
}

template <typename T>
std::ostream& operator<< (std::ostream& stream, const std::vector<T>& vec)
{
    for (size_t i = 0; i != vec.size(); ++i) {
	stream << vec[i] << ' ';
    }
    return stream;
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
	exit(EXIT_FAILURE); \
    } \

#define ASSERT_TRUE(condition) \
    if (!(condition)) { \
	printf("Assertion Fail at %s:line %d\n", __FILE__, __LINE__); \
	printf(#condition "\n"); \
	exit(EXIT_FAILURE); \
    } \



#endif
