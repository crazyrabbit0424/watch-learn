class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S, int sum, int idx) {
        if (idx == nums.size()) {
            if (S == sum)
                return 1;
            else
                return 0;
        }
        
        int res = findTargetSumWays(nums, S, sum + nums[idx], idx + 1);
        res += findTargetSumWays(nums, S, sum - nums[idx], idx + 1);
        return res;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWays(nums, S, 0, 0);
    }
};
