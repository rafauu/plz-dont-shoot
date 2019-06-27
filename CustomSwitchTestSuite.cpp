#include <gtest/gtest.h>
#include "CustomSwitch.hpp"

using ::testing::Test;

namespace
{
enum class TestParams
{
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight
};
}

struct CustomSwitchTestSuite : Test
{
    auto sutMethod(TestParams testParam)
    {
        Switch(testParam,
               Case(TestParams::One,
                    return "First")
               Case(TestParams::Two,
                    return "Second")
               Case(TestParams::Three,
                    TestParams::Five,
                    return "ThreeAndFive")
               Case(TestParams::Six,
                    return "AlmostLast")
               Default(return "Last"));
    }
};

TEST_F(CustomSwitchTestSuite, behaveProperlyWhileHandlingCommonCases)
{
    ASSERT_EQ(sutMethod(TestParams::One),   "First");
    ASSERT_EQ(sutMethod(TestParams::Two),   "Second");
}

TEST_F(CustomSwitchTestSuite, behaveProperlyWhileHandlingFallthroughCases)
{
    ASSERT_EQ(sutMethod(TestParams::Three), "ThreeAndFive");
    ASSERT_EQ(sutMethod(TestParams::Five),  "ThreeAndFive");
}

TEST_F(CustomSwitchTestSuite, behaveProperlyWhileHandlingCommonCasesAfterFallthrough)
{
    ASSERT_EQ(sutMethod(TestParams::Six),   "AlmostLast");
}

TEST_F(CustomSwitchTestSuite, behaveProperlyWhileHandlingDefaultCases)
{
    ASSERT_EQ(sutMethod(TestParams::Four),  "Last");
    ASSERT_EQ(sutMethod(TestParams::Seven), "Last");
    ASSERT_EQ(sutMethod(TestParams::Eight), "Last");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
