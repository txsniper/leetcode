#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
    public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        string max_prefix = strs[0];
        for(int i = 1; i < strs.size(); ++i)
        {
            string s = strs[i];
            int len = s.size() > max_prefix.size() ? max_prefix.size(): s.size();
            int j = 0;
            for(; j < len;)
            {
                char c1 = s[j];
                char c2 = max_prefix[j];
                if (c1 == c2)
                    j++;
                else
                    break;
            }
            if (j == 0)
                return "";
            else
            {
                max_prefix = max_prefix.substr(0, j);
            }
        }
        return max_prefix;
    }

    void test()
    {
        string s1 = "abc1234";
        string s2 = "abc1efg";
        string s3 = "a1234556";
        vector<string> sv;
        sv.push_back(s1);
        sv.push_back(s2);
        sv.push_back(s3);
        std::cout<< "output:" << longestCommonPrefix(sv) << std::endl;
    }
};

int main()
{
    Solution s;
    s.test();
    return 0;
}
