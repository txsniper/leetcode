class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n == 0)
            return 0;
        
        for(int i = 0; i < n; )
        {
            int value = A[i];
            if(value == elem)
            {
                
                A[i] = A[n-1];
                n--;
            }
            else
                i++;
        }
        return n;  
    }
};