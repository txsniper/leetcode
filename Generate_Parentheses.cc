#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class Solution {
    private:
        void generate(string s, int n, int sum, vector<string>& ret)
        {
            if (n == 0 && sum == 0)
            {
                ret.push_back(s);
                return;
            }

            if (n >= 0 && sum > 0)
            {
                generate(s + "(", n - 1, sum + 1, ret);
                generate(s + ")", n, sum - 1, ret);
            }
            else if (sum == 0)
            {
                generate(s + "(", n - 1, sum + 1, ret);
            }
        }
    public:
        vector<string> generateParenthesis(int n)
        {
            int sum = 0;
            vector<string> ret;
            generate("(", n - 1, 1, ret);
            return ret;
        }

        void test()
        {
            vector<string> ret = generateParenthesis(3);
            for(int i = 0; i < ret.size(); ++i)
            {
                std::cout << ret[i] << std::endl;
            }
        }
};

int main()
{
    Solution s;
    s.test();
    return 0;
}
