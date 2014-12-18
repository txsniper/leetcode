#include <vector>
#include <iostream>
#include <algorithm>
/*
 * step 1: 排序
 * step 2: 按顺序选取一个定值，求出剩下两个数的和，然后考察剩下的，寻找满足条件的两个值
 * note: 使用夹逼准则
 *
 */
using std::vector;
class Solution {
    public:
    vector<vector<int> > threeSum(vector<int> &num) {
        std::sort(num.begin(), num.end());
        vector<vector<int> > ret;
        int last_two_sum = 0;
        for(int i = 0; i < num.size(); ++i)
        {
            int two_sum = -num[i];
            // last_two_sum 初始为0，为了区别初始值和被赋值为0，判断
            // i是否等于0来考察last_two_sum是否已被赋过值
            if(i != 0 && last_two_sum == two_sum)
                continue;
            last_two_sum = two_sum;

            int last_bigger = 0;
            int last_smaller = 0;
            for(int j = i + 1, k = num.size() - 1; j < k; )
            {
                int cur_sum = num[j] + num[k];
                if (cur_sum > two_sum)
                    k--;
                else if (cur_sum < two_sum)
                    j++;
                else
                {
                    // 比较j与i+1是否相等来区别last_bigger，last_smaller初始为0和
                    // 被赋值为0的两种状态
                    if(last_bigger == num[k] && last_smaller == num[j] && j != i+1)
                    {
                        j++;
                        k--;
                        continue;
                    }
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[k]);
                    ret.push_back(tmp);
                    last_bigger = num[k];
                    last_smaller = num[j];
                    j++;
                    k--;
                }

            }
        }
        return ret;
    }

    void test()
    {
        int vec_int[] = {-3,-3,-2,-1,0,1,1,1,2,2,3,4,5};
        vector<int> input(vec_int, vec_int + sizeof(vec_int) / sizeof(int));
        vector<vector<int> > ret = threeSum(input);
        for(int i = 0; i < ret.size(); i++)
        {
            vector<int> cur = ret[i];
            std::cout<< cur[0] <<" "<<cur[1]<<" "<<cur[2]<<std::endl;
        }
    }
};

int main()
{
    Solution s;
    s.test();
}
