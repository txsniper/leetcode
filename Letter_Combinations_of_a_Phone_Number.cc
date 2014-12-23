#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;

class Solution {
    public:
    vector<string> letterCombinations(string digits) {
        string char_map[] = {" ", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ret;
        if (digits.empty())
        {
            ret.push_back("");
            return ret;
        }
        for(int i = 0; i < digits.length(); i++)
        {
            vector<string> tmp_ret;
            int d = digits[i] - '0';
            if (d < 0 || d > 9)
                return ret;
            string cur = char_map[d];
            if (ret.size() == 0)
            {
                for(int i = 0; i < cur.size(); ++i)
                {
                    char c = cur[i];
                    tmp_ret.push_back(string(1, c));
                }
            }
            else
            {
                for(int i = 0; i < ret.size(); ++i)
                {
                    for(int j = 0; j < cur.size(); ++j)
                    {
                        tmp_ret.push_back(ret[i] + cur[j]);
                    }
                }
            }
            ret = tmp_ret;
        }
        return ret;

    }

    void test()
    {
        vector<string> ret = letterCombinations("23");
        for(int i = 0; i < ret.size(); ++i)
            std::cout << ret[i] << std::endl;
    }

};

int main()
{
    Solution s;
    s.test();
    return 0;
}
