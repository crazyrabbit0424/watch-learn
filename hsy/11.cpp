class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i = 0, j = len - 1;
        int max = 0;
        while (i < j) {
            int rec = (j - i) * min(height[i], height[j]);
            if (rec > max)
                max = rec;
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        return max;
    }
};
