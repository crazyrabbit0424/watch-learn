class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int max_sub = 0;
        for (int n : nums) {
            if (max_sub > 0)
                max_sub += n;
            else
                max_sub = n;
            if (max_sub > max)
                max = max_sub;
        }
        return max;
    }
};
