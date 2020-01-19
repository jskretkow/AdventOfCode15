//#include <openssl/md5.h>
#include<iostream>
#include<sstream>
#include<iomanip>

class Day4
{
public:
    static int solvePart1(std::string input)
    {
        (void)input;

        int i {1};
/*
  TODO: link with OpenSSL
        while(true)
        {
            std::string str = input  + std::to_string(i++);

            unsigned char result[MD5_DIGEST_LENGTH];
            MD5((unsigned char*)str.c_str(), str.size(), result);

            std::ostringstream sout;
            sout<<std::hex<<std::setfill('0');
            for(long long c: result)
            {
                sout<<std::setw(2)<<(long long)c;
            }

            std::string s = sout.str();
            if (s.rfind("000000", 0) == 0)
            {
                return i;

            }
        }
        return 0;
*/
        return i;

    }
};
