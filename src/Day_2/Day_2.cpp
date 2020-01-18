#include <iostream>
#include <fstream>
#include <limits>
#include <array>

struct Box
{
    Box(int w_, int l_, int h_):
        w(w_),
        l(l_),
        h(h_) {}

    int w;
    int l;
    int h;

    int calculateGiftWrap()
    {
        return 2*l*w + 2*w*h + 2*h*l + getSmallesSide();
    }

    int getSmallesSide()
    {
        int first = std::numeric_limits<int>::max();
        int second = std::numeric_limits<int>::max();

        std::array<int, 3> arr  {w, l , h};

        for (auto i : arr)
        {
            if (i <= first)
            {
                second = first;
                first = i;
            }
            else if (i < second  && i != first)
                second = i;

        }
        std::cout << "Box dimensions are: w = " << w << ", l = " << l << ", h = " << h <<
            "SMALLES :: " << first  << ", "  << second << std::endl;

        return first * second;
    }



};

int main()
{
    std::ifstream inputFile("input");
    char sep1, sep2;
    int w,l,h;

    long int giftWrap = 0;
    while(inputFile >> l  >> sep1 >> w >> sep2 >>  h)
    {
        Box box{w,l,h};
        std::cout << "Gift wrap needed for box : " <<box.calculateGiftWrap() << std::endl;

        giftWrap += box.calculateGiftWrap();
    }

    std::cout << "Full Gift wrap needed for boxes : " << giftWrap << std::endl;

    Box x {1, 1 , 10};
    std::cout << "Full Gift wrap needed for boxes : " << x.calculateGiftWrap() << std::endl;



    return 0;
}
