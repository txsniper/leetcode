#include <map>
#include <iostream>
#include <string>
#include <string.h>
/*
 * 想法：字符串：abcdbfegh
 *   map存放已经出现的字符和下标，j表示子串的开始下标,
 *   i表示当前字符下标，每次碰到新字符，都去map中查看是
 *   否已经出现过，如果已经出现过，则从map中去掉从j开始
 *   到重复字符第一次出现的下一个位置的数据：
 *      例如：当i指向第二个b时，查找map发现已经出现过b，
 *   则从map中去掉key为a，b的数据，map中仍然保存key为c，d的
 *   数据
 *
 */
using std::string;
using std::map;
class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        std::map<char, int> m;
        size_t len = 0;
        size_t i = 0;
        size_t j = 0;
        for (; i < s.length(); i++)
        {
            char c = s[i];
            if (m.find(c) == m.end())
            {
                m[c] = i;
            }

            else
            {
                // 如果已经在map中出现过，则先计算这个字串的长度
                if ((i - j) > len)
                {
                    len = i - j;
                }
                // 获取首次出现的下标
                int end = m[c] + 1;

                // 从map中删除掉从j开始到重复字符首次出现的数据
                for(int k=j; k < end; k++)
                {
                    char d = s[k];
                    m.erase(m.find(d));
                }
                // 设置字串的新起点
                j = end;
                m[c] = i;

            }
        }
        if ((i - j) > len)
            len = i - j;
        return len;
    }
    void test()
    {
        std::string s("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
        //std::string s("bbb");
        int ret = lengthOfLongestSubstring(s);
        std::cout<< ret <<std::endl;
    }

};

int main()
{
    Solution s;
    s.test();
    return 0;
}
