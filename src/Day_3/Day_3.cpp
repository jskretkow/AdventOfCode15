#include<iostream>
#include<fstream>
#include<unordered_map>

struct PresentMover
{
    int x;
    int y;

  bool operator==(const PresentMover &other) const
  {
      return (x == other.x && y == other.y);
  }

};

namespace std
{

template <>
struct hash<PresentMover>
{
    std::size_t operator()(const PresentMover& k) const
    {
        return ((k.x << 16) ^ k.y);

    }
};

}

class Day3
{
public:
    static void makeMove(PresentMover& mover, char move)
    {
        switch (move)
        {
            case '<':
                --mover.x;
                break;
            case '>':
                ++mover.x;
                break;
            case 'v':
                --mover.y;
                break;
            case '^':
                ++mover.y;
                break;
        }
    }

    static int solvePart1(std::ifstream& input)
    {
        PresentMover santa {0,0};
        std::unordered_map<PresentMover,int> houses;

        char c;
        while(input >> c)
        {
            makeMove(santa, c);

            if (houses.find(santa) != houses.end())
            {
                houses.at(santa)++;
            }
            else
            {
                houses[santa] = 1;
            }
        }
        return houses.size();
    }

    static int solvePart2(std::ifstream& input)
    {
        PresentMover santa {0, 0};
        PresentMover robot {0, 0};

        bool forSanta {true};

        std::unordered_map<PresentMover,int> houses;

        char c;
        while(input >> c)
        {
            auto& mover = (forSanta) ? santa : robot;

            makeMove(mover, c);

            if (houses.find(mover) != houses.end())
            {
                houses.at(mover)++;
            }
            else
            {
                houses[mover] = 1;
            }

            forSanta = !forSanta;
        }
        return houses.size();
    }
};
