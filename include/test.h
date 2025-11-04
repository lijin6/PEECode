#ifndef TEST_H
#define TEST_H

#include <stdio.h>

#define TEST_CASE(name) void name()
#define ASSERT_EQ(a, b) \
    if ((a) != (b)) printf("[FAIL] %s: %s != %s\n", __func__, #a, #b); \
    else printf("[PASS] %s: %s == %s\n", __func__, #a, #b);

#endif
