#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
using std::map;
using std::vector;
using std::pair;

typedef struct MidData_t
{
    std::vector<std::pair<int, int> > data;
    bool used;
} MidData;
class Solution {
    public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        std::sort(num.begin(), num.end());
        vector<vector<int> > ret;
        std::map<int, MidData > sum_num_map;
        for(int i = 0; i < num.size(); i++)
        {
            int j = i + 1;
            if (num[i] == num[j])
                // skip duplicate
                continue;
            for(; j < num.size(); j++)
            {
                if (num[j] == num[j+1])
                    // skit duplicate
                    continue;
                //sum_num_map[num[i] + num[j]].data.push_back(std::make_pair(i, j));
                sum_num_map[num[i] + num[j]].data.push_back(std::make_pair(num[i], num[j]));
                sum_num_map[num[i] + num[j]].used = false;
            }
        }
        for(std::map<int, MidData >::iterator it = sum_num_map.begin(); it != sum_num_map.end(); ++it)
        {
            int value = target - it->first;
            it->second.used = true;
            std::map<int, MidData >::iterator it_value = sum_num_map.find(value);
            if (it_value != sum_num_map.end() && it_value->second.used == false)
            {
                it_value->second.used  = true;
                for(std::vector<std::pair<int, int> >::iterator it_data_1 = (it->second).data.begin(); it_data_1 != (it->second).data.end(); ++it_data_1)
                {
                    for(std::vector<std::pair<int, int> >::iterator it_data_2 = it_value->second.data.begin(); it_data_2 != it_value->second.data.end(); ++it_data_2)
                    {
                        std::pair<int,int> a = *it_data_1;
                        std::pair<int,int> b = *it_data_2;
                        std::cout<< a.first << " "<< a.second << std::endl;
                        std::cout << b.first << " " << b.second << std::endl;
                        int temp[] = {a.first, a.second, b.first, b.second};
                        std::cout<<"res: " << a.first <<a.second<<b.first << " " << b.second << std::endl;

                        std::vector<int> cur(temp, temp + sizeof(temp)/ sizeof(int));
                        std::sort(cur.begin(), cur.end());
                        ret.push_back(cur);
                    }
                }
            }
        }
        return ret;

    }

    void test()
    {
        int int_temp[] = {1,0,-1,0,-2,2};
        std::vector<int> test_data(int_temp, int_temp + sizeof(int_temp)/ sizeof(int));
        vector< vector<int> > ret = fourSum(test_data, 0);
        for(vector< vector<int> >::iterator it = ret.begin(); it != ret.end(); ++it)
        {
            std::cout<< std::endl;
            for(vector<int>::iterator ij = it->begin(); ij != it->end(); ++ij)
            {
                std::cout<<*ij;
            }
            std::cout<< std::endl;
        }
    }
};

int main()
{
    Solution s;
    s.test();
    return 0;
}
