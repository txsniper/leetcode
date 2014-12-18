/*
 * 从两侧向中间，高度小的移动
 */
class Solution {
    public:
    int maxArea(vector<int> &height) {
        int area = 0;
        for(int i=0, j = height.size() - 1; i != j;)
        {
            int h1 = height[i];
            int h2 = height[j];
            int cur_area = (j-i) * (h1>h2?h2:h1);
            if (area < cur_area)
                area = cur_area;
            if (h1 < h2)
                i++;
            else
                j--;
        }
        return area;
    }

};
