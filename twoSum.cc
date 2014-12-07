#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
class Solution
{
    private:
        void sort(std::vector< std::pair<int, int> > &ns_index, int left, int right)
        {
            if(left < right)
            {
                int mid = (right + left) / 2;
                std::swap(ns_index[left], ns_index[mid]);
                std::pair<int, int> key_pair = ns_index[left];
                size_t i = left;
                size_t j = right;
                while ( i < j )
                {
                    while( (i < j) && (ns_index[j].first >= key_pair.first))
                        --j;
                    if(i < j)
                    {
                        ns_index[i] = ns_index[j];
                        ++i;
                    }
                    while((i < j) && (ns_index[i].first < key_pair.first))
                        ++i;
                    if(i < j)
                    {
                        ns_index[j] = ns_index[i];
                        --j;
                    }
                }
                ns_index[i] = key_pair;
                sort(ns_index, left, i - 1);
                sort(ns_index, i + 1, right);
            }
        }
    public:
        std::vector<int> twoSum(std::vector<int>& numbers, int target)
        {
            std::vector<int> rets;
            std::vector< std::pair<int, int> > ns_index;
            for(int i = 0; i < numbers.size(); ++i)
                ns_index.push_back(std::pair<int, int> (numbers[i], i));

            sort(ns_index, 0, numbers.size() - 1);
            int i = 0;
            int j = numbers.size() - 1;
            while(i < j)
            {
                int total = ns_index[i].first + ns_index[j].first;
                if(total < target)
                    ++i;
                else if(total > target)
                    --j;
                else
                {
                    if(ns_index[i].second < ns_index[j].second)
                    {
                        rets.push_back(ns_index[i].second + 1);
                        rets.push_back(ns_index[j].second + 1);
                    }
                    else
                    {
                        rets.push_back(ns_index[j].second + 1);
                        rets.push_back(ns_index[i].second + 1);
                    }
                    return rets;
                }

            }
        }

        void test()
        {
            std::vector<int> ns;
            ns.push_back(2);
            ns.push_back(1);
            ns.push_back(9);
            ns.push_back(4);
            ns.push_back(4);
            ns.push_back(56);
            ns.push_back(90);
            ns.push_back(3);
            for(size_t i = 0; i < ns.size(); i++)
            {
                std::cout<< ns[i] << std::endl;
            }
            std::vector<int> ret = twoSum(ns, 8);
            for(size_t i = 0; i < ret.size(); i++)
            {
                std::cout<<"index="<<ret[i]<<" value="<<ns[ret[i]-1] << std::endl;
            }

        }
};

int main()
{
    Solution t;
    t.test();
    std::cout<<std::endl;
}
