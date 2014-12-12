/*
 * 1.注意900100之类的，两个非零数字之间含有零的，必须乘以10
 * 2.注意int overflow
 *
 */

#include <iostream>
using namespace std;
class Solution {
    public:
    int reverse(int x) {
        int out = 0;
        int out_start = 0;
        bool start = false;
        for(int i = x; i != 0; )
        {
            int j = i % 10;
            if (j != 0 || start)
            {
                out = 10 * out_start + j;
                int check = out / 10;
                if (check != out_start)
                {
                    // integer overflow
                    return 0;
                }
                out_start = out;
                start = true;
            }
            i = i / 10;
        }
        return out;
    }
    void test()
    {
        int i = reverse(123);
        int j = reverse(1534236469);
        int k = reverse(-901000);
        cout<<i<<" "<<j<<" "<<k << endl;
    }

};

int main()
{
    Solution s;
    s.test();
}
