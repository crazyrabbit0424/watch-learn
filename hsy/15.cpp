class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 3)
            return res;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len;) {
            int sum = -nums[i];
            if (sum < 0)
                break;
            
            int j = i + 1, k = len - 1;
            while (j < k) {
                int data = nums[j] + nums[k];
                if (data == sum)
                    res.push_back({nums[i], nums[j], nums[k]});
                if (data >= sum) {
                    do {
                        --k;
                    } while (j < k && nums[k] == nums[k + 1]);
                } else {
                    do {
                        ++j;
                    } while (j < k && nums[j] == nums[j - 1]);
                }
            }
            
            do {
                ++i;
            } while (i < len && nums[i] == nums[i - 1]);
        }
        return res;
    }
};
