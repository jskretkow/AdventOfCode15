#include <gtest/gtest.h>
#include <Day_2/Day_2.cpp>


TEST(Day2, parseLine)
{
    GiftBox box = Day2::parseLine("6x10x13");

    EXPECT_EQ(box.l, 6);
    EXPECT_EQ(box.w, 10);
    EXPECT_EQ(box.h, 13);
}

TEST(Day2, giftWrapCalculation)
{
    /*
      A present with dimensions 2x3x4 requires 2*6 + 2*12 + 2*8 = 52 square feet of wrapping paper plus 6 square feet of slack, for a total of 58 square feet.
      A present with dimensions 1x1x10 requires 2*1 + 2*10 + 2*10 = 42 square feet of wrapping paper plus 1 square foot of slack, for a total of 43 square feet.
    */

    GiftBox box = Day2::parseLine("2x3x4");
    EXPECT_EQ(box.calculateGiftWrap(), 58);

    box = Day2::parseLine("1x1x10");
    EXPECT_EQ(box.calculateGiftWrap(), 43);
}

TEST(Day2, RibbonCalculation)
{
    /*
      A present with dimensions 2x3x4 requires 2+2+3+3 = 10 feet of ribbon to wrap the present plus 2*3*4 = 24 feet of ribbon for the bow, for a total of 34 feet.
      A present with dimensions 1x1x10 requires 1+1+1+1 = 4 feet of ribbon to wrap the present plus 1*1*10 = 10 feet of ribbon for the bow, for a total of 14 feet.
    */

    GiftBox box = Day2::parseLine("2x3x4");
    EXPECT_EQ(box.getRibbon(), 34);

    box = Day2::parseLine("1x1x10");
    EXPECT_EQ(box.getRibbon(), 14);
}

TEST(Day2, solvePart_1_And_2)
{
    std::ifstream inputFile("../tst/Day_2/input");
    auto solution = Day2::solvePart1And2(inputFile);

    std::cout <<"\n[Day 2 p.1] - solution :  " << solution.first << std::endl;
    std::cout <<"[Day 2 p.2] - solution :  " << solution.second << "\n\n";
}
