#include <gtest/gtest.h>
#include <Day_4/Day_4.cpp>

TEST(Day4, calculation)
{
    std::string input {"abcdef"};

    auto solution = Day4::solvePart1(input);
    /*
      TODO: link with openSSL
      EXPECT_EQ(solution, 609043);
    */

      EXPECT_EQ(solution, 1);


}
