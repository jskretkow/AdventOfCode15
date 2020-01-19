#include <gtest/gtest.h>
#include <Day_5/Day_5.cpp>

TEST(Day5, checks_1)
{
    std::string exampleStr {"ugknbfddgicrmopn"};

    EXPECT_TRUE(Day5::atLeastThreeVowels(exampleStr));
    EXPECT_TRUE(Day5::repeatingChars(exampleStr));
    EXPECT_TRUE(Day5::prohibitedStrings(exampleStr));
    EXPECT_TRUE(Day5::isItNice(exampleStr));
}

TEST(Day5, checks_2)
{
    std::string exampleStr {"aaa"};

    EXPECT_TRUE(Day5::atLeastThreeVowels(exampleStr));
    EXPECT_TRUE(Day5::repeatingChars(exampleStr));
    EXPECT_TRUE(Day5::prohibitedStrings(exampleStr));
    EXPECT_TRUE(Day5::isItNice(exampleStr));
}

TEST(Day5, checks_3)
{
    std::string exampleStr {"jchzalrnumimnmhp"};

    EXPECT_TRUE(Day5::atLeastThreeVowels(exampleStr));
    EXPECT_FALSE(Day5::repeatingChars(exampleStr));
    EXPECT_TRUE(Day5::prohibitedStrings(exampleStr));
    EXPECT_FALSE(Day5::isItNice(exampleStr));
}

TEST(Day5, checks_4)
{
    std::string exampleStr {"haegwjzuvuyypxyu"};

    EXPECT_TRUE(Day5::atLeastThreeVowels(exampleStr));
    EXPECT_TRUE(Day5::repeatingChars(exampleStr));
    EXPECT_FALSE(Day5::prohibitedStrings(exampleStr));
    EXPECT_FALSE(Day5::isItNice(exampleStr));
}

TEST(Day5, checks_5)
{
    std::string exampleStr {"dvszwmarrgswjxmb"};

    EXPECT_FALSE(Day5::atLeastThreeVowels(exampleStr));
    EXPECT_TRUE(Day5::repeatingChars(exampleStr));
    EXPECT_TRUE(Day5::prohibitedStrings(exampleStr));
    EXPECT_FALSE(Day5::isItNice(exampleStr));
}

TEST(Day5, solvePart_1)
{
    std::ifstream inputFile("../tst/Day_5/input");
    auto solution = Day5::solvePart1(inputFile);

    std::cout <<"\n[Day 5 p.1] - solution :  " << solution << std::endl;
}

TEST(Day5, checks_6)
{
    EXPECT_TRUE(Day5::twoLetterCombination("xyxy"));
    EXPECT_FALSE(Day5::twoLetterCombination("aaa"));
}

TEST(Day5, checks_7)
{
    EXPECT_TRUE(Day5::twoLetterSeparated("xyx"));
    EXPECT_TRUE(Day5::twoLetterSeparated("abcdefeghi"));
    EXPECT_TRUE(Day5::twoLetterSeparated("aaa"));
    EXPECT_FALSE(Day5::twoLetterSeparated("abcdeffghi"));
}

TEST(Day5, checks_8)
{
    std::string exampleStr {"qjhvhtzxzqqjkmpb"};
    EXPECT_TRUE(Day5::twoLetterSeparated(exampleStr));
    EXPECT_TRUE(Day5::twoLetterCombination(exampleStr));
    EXPECT_TRUE(Day5::isItNicePart2(exampleStr));
}

TEST(Day5, checks_9)
{
    std::string exampleStr {"xxyxx"};
    EXPECT_TRUE(Day5::twoLetterSeparated(exampleStr));
    EXPECT_TRUE(Day5::twoLetterCombination(exampleStr));
    EXPECT_TRUE(Day5::isItNicePart2(exampleStr));
}

TEST(Day5, checks_10)
{
    std::string exampleStr {"uurcxstgmygtbstg"};
    EXPECT_FALSE(Day5::twoLetterSeparated(exampleStr));
    EXPECT_TRUE(Day5::twoLetterCombination(exampleStr));
    EXPECT_FALSE(Day5::isItNicePart2(exampleStr));
}

TEST(Day5, checks_11)
{
    std::string exampleStr {"ieodomkazucvgmuy"};
    EXPECT_TRUE(Day5::twoLetterSeparated(exampleStr));
    EXPECT_FALSE(Day5::twoLetterCombination(exampleStr));
    EXPECT_FALSE(Day5::isItNicePart2(exampleStr));
}

TEST(Day5, solvePart_2)
{
    std::ifstream inputFile("../tst/Day_5/input");
    auto solution = Day5::solvePart1(inputFile, true);

    std::cout <<"\n[Day 5 p.2] - solution :  " << solution << std::endl;
}
