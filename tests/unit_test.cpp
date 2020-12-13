#include "gtest/gtest.h"
#include "composite_test.hpp"
#include "strategy_test.hpp"
#include "observer_test.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
