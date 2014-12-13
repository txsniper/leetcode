#include <iostream>
#include <climits>
#include <string.h>
class Solution {
    public:
    int atoi(const char *str) {
        if(str)
        {
            int ret = 0;
            int ret_saved = 0;
            const char *p = str;
            bool negative = false;
            bool overflow = false;
            while (*p == ' ' || *p == '\t')
                p++;

            if(*p == '-')
            {
                negative = true;
                p++;
            }
            else if(*p == '+')
            {
                p++;
            }
            while(*p != '\0')
            {
                int cur = *p - '0';
                if (cur < -9 || cur > 9)
                    break;

                if (negative)
                    cur = -cur;

                ret_saved = ret * 10 + cur;
                int check = ret_saved / 10;
                if (check != ret && !negative)
                {
                    return INT_MAX;
                }
                if(check != ret && negative)
                {
                    return INT_MIN;
                }
                ret = ret_saved;
                p++;
            }
            return ret;
        }

    }

    void test()
    {
        int ret = atoi("    10522545459");
        std::cout<< ret << std::endl;
        ret = atoi("-1");
        std::cout<< ret << std::endl;
    }

};

int main()
{
    Solution s;
    s.test();

}
