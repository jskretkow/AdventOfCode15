#include<iostream>
#include<fstream>
#include<unordered_map>
#include <set>


class Day5
{
public:
    static int solvePart1(std::ifstream& inputFile, bool secondPart = false)
    {
        int niceCount {0};

        std::string line;
        while(inputFile >> line)
        {
            if (secondPart? isItNicePart2(line) : isItNice(line))
                niceCount++;
        }
        return niceCount;
    }

    static bool isItNice(std::string str)
    {
        return atLeastThreeVowels(str) && repeatingChars(str) && prohibitedStrings(str);
    }

    static bool isItNicePart2(std::string str)
    {
        return twoLetterSeparated(str) && twoLetterCombination(str);
    }

    static bool atLeastThreeVowels(const std::string str)
    {
        std::set<char> vowels {'a', 'e', 'i', 'o', 'u'};
        int count {0};

        for (const auto c :  str)
        {
            if (vowels.find(c) != vowels.end())
            {
                count++;

                if (count == 3)
                {
                    return true;
                }
            }
        }

        return false;
    }

    static bool repeatingChars(const std::string str)
    {
        char lastChar = str[0];
        bool skip = true;

        for (const auto c :  str)
        {
            if (!skip)
            {
                if (lastChar == c)
                    return true;
                else
                    lastChar = c;
            }
            else
            {
                skip = false;
            }
        }

        return false;
    }

    static bool prohibitedStrings(const std::string str)
    {
        std::set<std::string> prohibited {"ab", "cd", "pq",  "xy"};
        for(const auto s : prohibited)
        {
            if (str.find(s) != std::string::npos)
                return false;
        }
        return true;
    }


    static bool twoLetterCombination(const std::string str)
    {
        int i1 {0};
        int i2 {1};

        for (i1 = 0, i2 = 1; i2 < str.size() - 1; ++i1, ++i2)
        {
            std::string temp {str[i1] , str[i2]};

            if (str.find(temp, i2 + 1) != std::string::npos)
                return true;

        }
        return false;
    }

    static bool twoLetterSeparated(const std::string str)
    {
        int i1 {0};
        int i2 {2};

        for (i1 = 0, i2 = 2; i2 < str.size(); ++i1, ++i2)
        {
            if (str[i1] == str[i2])
                return true;
        }
        return false;
    }

};
