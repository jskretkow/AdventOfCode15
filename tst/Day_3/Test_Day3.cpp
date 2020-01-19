#include <gtest/gtest.h>
#include <Day_3/Day_3.cpp>

TEST(Day3, moveDecision)
{
    PresentMover p1 {0,0};

    Day3::makeMove(p1, '>');
    EXPECT_EQ(p1.x, 1);
    EXPECT_EQ(p1.y, 0);

    Day3::makeMove(p1, '^');
    EXPECT_EQ(p1.x, 1);
    EXPECT_EQ(p1.y, 1);

    Day3::makeMove(p1, '<');
    EXPECT_EQ(p1.x, 0);
    EXPECT_EQ(p1.y, 1);

    Day3::makeMove(p1, 'v');
    EXPECT_EQ(p1.x, 0);
    EXPECT_EQ(p1.y, 0);

}

TEST(Day3, solvePart_1)
{
    std::ifstream inputFile("../tst/Day_3/input");
    auto solution = Day3::solvePart1(inputFile);

    std::cout <<"\n[Day 3 p.1] - solution :  " << solution << std::endl;
}

TEST(Day3, solvePart_2)
{
    std::ifstream inputFile("../tst/Day_3/input");
    auto solution = Day3::solvePart2(inputFile);

    std::cout <<"\n[Day 3 p.2] - solution :  " << solution << std::endl;
}
