class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int cnt = nums.size();
        int sum = 1;
        for (int i = cnt - 3; i < cnt; ++i)
            sum *= nums[i];
        
        if (nums[0] > 0) {
            return sum;
        } else if (nums[1] < 0) {
            if (nums[0] *nums[1] > nums[cnt - 2] * nums[cnt - 3])
                sum = nums[0] * nums[1] * nums[cnt - 1];
            return sum;
        }
        return sum;
    }
};
