#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
    public:
     static char** char_map = {
        {'a', 'b', 'c', NULL},
        {'d', 'e', 'f', NULL},
        {'g', 'h', 'i', NULL},
        {'j', 'k', 'l', NULL},
        {'m', 'n', 'o', NULL},
        {'p', 'q', 'r', 's', NULL},
        {'t', 'u', 'v', NULL},
        {'w', 'x', 'y', 'z', NULL},
        NULL
    };
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        for(int i = 0; i < digits.length(); i++)
        {
            int d = digits[i] - '0';
        }

    }

};
