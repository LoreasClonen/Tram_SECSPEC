//
// Created by Luuk on 3/16/17.
//

#include <assert.h>

#define REQUIRE(assertion, what) \
    if (!(assertion)) __assert (what, __FILE__, __LINE__)

#define ENSURE(assertion, what) \
    if(!(assertion)) __assert (what, __FILE__, __LINE__)



