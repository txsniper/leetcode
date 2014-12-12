/*   P   A   H   N
 *   A P L S I I G
 *   Y   I   R
 *  两条长竖线之间的间隔是foot_length =  2 * (nRows - 1)
 *  除开第一行和最后一行之外，其他每行都有短竖线，短竖线字母
 *  下标就是index1 = foot_length - 2 * i + j
 *
 */
#include <string.h>
#include <string>
#include <iostream>
using std::string;
class Solution {
    public:
    string convert(string s, int nRows) {
        // 注意nRows为1的边界条件
        if (nRows <= 1)
            return s;
        int length = s.size();
        string out;
        int foot_length = 2 * (nRows - 1);
        for(int i = 0; i < nRows; i++)
        {
            for(int j = i; j < length; )
            {
                out = out + s[j];
                int index1 = foot_length - 2 * i + j;
                if (index1 >= length )
                    break;
                if (index1 != j && index1 != (j + foot_length))
                    out = out + s[index1];
                j = j + foot_length;
            }
        }
        return out;
    }

    void test(string s, int nRows)
    {
        string out = convert(s, nRows);
        std::cout<<out<<std::endl;
    }

};

int main()
{
    Solution s;
    s.test("PAYPALISHIRING", 3);
    s.test("A", 1);
}
