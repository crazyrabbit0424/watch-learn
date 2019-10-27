class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = len - 1; i > 0; --i) {
            int diff = nums[i] - nums[0];
            res += diff;
        }
        return res;
    }
};
