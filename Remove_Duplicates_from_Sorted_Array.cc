#include <string.h>
#include <iostream>

class Solution
{
    public:
        int removeDuplicates(int A[], int n) {
            if (n <= 1)
                return n;
            int start = 0;
            int same_value_count = 0;
            int length = n;
            int last_value = A[0];
            for(int i = 1; i < length; )
            {
                int cur_value = A[i];
                if (cur_value == last_value)
                {
                    same_value_count++;
                    i++;
                }
                else
                {
                    last_value = cur_value;
                    length = length - same_value_count;
                    memmove(A+start, A+start+same_value_count, length * sizeof(int));
                    start++;
                    i = start + 1;
                    same_value_count = 0;
                }
            }
            length = length - same_value_count;
            memmove(A+start, A+start+same_value_count, length * sizeof(int));
            return length;
        }

        void test()
        {
            int A[] = {0,2,3};
            int length = sizeof(A) / sizeof(int);
            int len = removeDuplicates(A, length);
            for(int i = 0; i < len; i++)
                std::cout<< A[i] << std::endl;
        }
};

int main()
{
    Solution s;
    s.test();
    return 0;
}
