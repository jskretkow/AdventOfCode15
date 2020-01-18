#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <sstream>

struct GiftBox
{
    int w;
    int l;
    int h;

    /*
      ...[from TASK]
      Fortunately, every present is a box (a perfect right rectangular prism),
      which makes calculating the required wrapping paper for each gift a little easier:
      find the surface area of the box, which is 2*l*w + 2*w*h + 2*h*l.
      The elves also need a little extra paper for each present: the area of the smallest side.
    */

    int calculateGiftWrap()
    {
        return (2 * l * w) + (2 * w * h) + (2 * h * l) + getSmallestSideArea();
    }

    int getSmallestSideArea()
    {
        std::array<int, 3> dims  {w, l , h};
        std::sort(dims.begin(), dims.end());

        return dims[0] * dims[1];
    }

    int getSmallestSidePerimeter()
    {
        std::array<int, 3> dims  {w, l , h};
        std::sort(dims.begin(), dims.end());

        return 2* dims[0] + 2 * dims[1];
    }

    int getRibbonBow()
    {
        return w * l * h;
    }

    int getRibbon()
    {
        return getSmallestSidePerimeter() + getRibbonBow();
    }
};

class Day2
{
public:
    static GiftBox parseLine(std::string line)
    {
        std::istringstream ifStrLine(line);

        char sep1, sep2;
        int w {0};
        int l {0};
        int h {0};

        ifStrLine >> l  >> sep1 >> w >> sep2 >>  h;
        GiftBox box {w, l, h};

        return box;
    }

    static std::pair<int, int> solvePart1And2(std::ifstream& inputFile)
    {
        int giftWrap {0};
        int ribbon {0};
        std::string line;

        while(std::getline(inputFile, line))
        {
            GiftBox box = parseLine(line);
            giftWrap += box.calculateGiftWrap();
            ribbon += box.getRibbon();

        }
        return {giftWrap, ribbon};
    }
};
