#include <iostream>
#include <cstdlib>
#include <string.h>
class Solution {
    private:
    char* itoa_reserve(int x, char* str, int len);
    {
        int i = 0;
        if(x < 0)
            str[i++] = '-';
        while(x != 0 && i < len)
        {
            int tmp = x % 10;
            str[i++] = tmp + '0';
            x = x / 10;
        }
        str[i] = '\0';
        return str;
    }
    public:
    bool isPalindrome(int x) {
        char tmp[32] = {0};
        char* str = itoa_reserve(x, tmp, sizeof tmp);
        int len = ::strlen(str);
        for(int i = 0; i < len/2; i++)
        {
            if(str[i] != str[len - 1 - i])
                return false;
        }
        return true;

    }
};
