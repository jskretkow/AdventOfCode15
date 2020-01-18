#include<iostream>
#include<fstream>

class Day1
{
public:
    static int getChange(char c) { return (c == '(') ? 1 : -1; }

    static std::pair<int, int> solvePart1And2(std::ifstream& input)
    {
        char c;
        int startFloor {0};
        int index {0};
        bool searchForBasement = true;

        while(input >> c)
        {
            startFloor += getChange(c);

            /* part 2 - index of char (first time in basement) [-1] */
            if (searchForBasement)
            {
                ++index;
                if(startFloor == -1)
                    searchForBasement = false;
            }
        }

        return {startFloor, index};
    }
};
