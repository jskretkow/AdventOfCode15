#include <gtest/gtest.h>
#include <Day_1/Day_1.cpp>

TEST(Day1, solvePart_1_And_2)
{
    std::ifstream inputFile("../tst/Day_1/input");

    auto solution = Day1::solvePart1And2(inputFile);
    std::cout <<"[Day 1 p.1] - solution :  " << solution.first << std::endl;
    std::cout <<"[Day 1 p.2] - solution :  " << solution.second << std::endl;
}

TEST(Day1, actions)
{
    EXPECT_EQ(Day1::getChange('('), 1);
    EXPECT_EQ(Day1::getChange(')'), -1);
}
