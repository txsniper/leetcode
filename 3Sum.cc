#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
class Solution {
    public:
    vector<vector<int> > threeSum(vector<int> &num) {
        std::sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); ++i)
        {
            int two_sum = -num[i];
            for(int j = i + 1, k = num.size() - 1; j < k; )
            {
                int cur_sum = num[j] + num[k];
                if (cur_sum > two_sum)
                    k--;
                else if (cur_sum < two_sum)
                    j++;
                else
            }
        }
    }
};
