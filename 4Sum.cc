#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using std::map;
using std::vector;
using std::pair;

typedef struct MidData_t
{
    std::vector<std::pair<size_t, size_t> > data;
} MidData;
class Solution {
    public:
    size_t getHashKey(std::vector<int>& arr)
    {
        size_t hash_code = 0;
        for(int i = 0; i < arr.size(); ++i)
        {
            hash_combine(hash_code, arr[i]);
        }
        return hash_code;
    }

    void hash_combine(std::size_t& h, const std::size_t& v)
    {
        h ^= v + 0x9e3779b9 + (h << 6) + (h >> 2);
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        std::sort(num.begin(), num.end());
        vector<vector<int> > ret;
        std::map<int, MidData > sum_num_map;
        for(size_t i = 0; i < num.size(); i++)
        {
            size_t j = i + 1;
            for(; j < num.size(); j++)
            {
                sum_num_map[num[i] + num[j]].data.push_back(std::make_pair(i, j));
            }
        }
        std::map<size_t, int> hash_code_map;
        for(std::map<int, MidData >::iterator it = sum_num_map.begin(); it != sum_num_map.end(); ++it)
        {
            int value = target - it->first;
            std::map<int, MidData >::iterator it_value = sum_num_map.find(value);
            if (it_value != sum_num_map.end())
            {
                for(std::vector<std::pair<size_t, size_t> >::iterator it_data_1 = (it->second).data.begin(); it_data_1 != (it->second).data.end(); ++it_data_1)
                {
                    for(std::vector<std::pair<size_t, size_t> >::iterator it_data_2 = it_value->second.data.begin(); it_data_2 != it_value->second.data.end(); ++it_data_2)
                    {
                        std::pair<size_t,size_t> a = *it_data_1;
                        std::pair<size_t,size_t> b = *it_data_2;
                        if(a.first == b.first || a.second == b.first || a.first == b.second || a.second == b.second)
                            continue;
                        int temp[] = {num[a.first], num[a.second], num[b.first] , num[b.second]};
                        std::vector<int> arr(temp, temp + sizeof(temp)/sizeof(size_t));
                        std::sort(arr.begin(), arr.end());
                        size_t hash_code = getHashKey(arr);
                        if (hash_code_map.find(hash_code) == hash_code_map.end())
                        {
                            std::cout<< "hash_code = "<< hash_code << std::endl;
                            ret.push_back(arr);
                            hash_code_map[hash_code] = 1;
                        }
                    }
                }
            }
        }
        return ret;

    }

    void test()
    {
        //int int_temp[] = {1,0,-1,0,-2,2};
        int int_temp[] = {-3,-2,-1,0,0,1,2,3};
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
