class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());
        
        int start = 0, end = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nums[i] != nums2[i]) {
                start = i - 1;
                break;
            }
        }
        for (int i = len - 1; i >= 0; --i) {
            if (nums[i] != nums2[i]) {
                end = i;
                break;
            }
        }
        
        if (start >= end)
            return 0;
        return end - start;
    }
};
