class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        map<int, int> val;
        int sum = 0;
        int len = nums.size();
        for (int n : nums) {
            sum += n;
            if (val.count(sum - k))
                res += val[sum - k];
            if (sum == k)
                ++res;
            ++val[sum];
        }
        
        return res;
    }
};
