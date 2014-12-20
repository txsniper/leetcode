#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
/*  step 1: 排序
 *  step 2: 从小到大(or 从大到小) 选取一个定值，然后计算一个需要最接近的值
 *  step 3: 从两侧向中间夹逼剩下的值
 */
using std::vector;

class Solution {
    public:
    int threeSumClosest(vector<int> &num, int target) {
        std::sort(num.begin(), num.end());
        int last_closest_number[3] = {0};
        int last_closest_diff = -1;
        for(int i = 0; i < num.size(); ++i)
        {
            int cur_closest = target - num[i];
            for(int j = i+1, k = num.size() - 1; j < k; )
            {
                int cur_sum = num[j] + num[k];
                int cur_diff = std::abs(cur_sum - cur_closest);
                if (last_closest_diff < 0 || last_closest_diff > cur_diff)
                {
                    last_closest_diff = cur_diff;
                    last_closest_number[0] = num[i];
                    last_closest_number[1] = num[j];
                    last_closest_number[2] = num[k];
                }
                if (cur_sum > cur_closest)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return last_closest_number[0] + last_closest_number[1] + last_closest_number[2];
    }

    void test()
    {
        int temp[] = {-1,2,1,-4};
        vector<int> in(temp, temp + sizeof(temp) / sizeof(int));
        int ret = threeSumClosest(in, 1);
        std::cout<< "closest: " << ret << std::endl;
    }

};

int main()
{
    Solution s;
    s.test();
    return 0;
}
