class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int next = 0;
        int i = 0;
        while (i < len) {
            int last = nums[i];
            int j = i;
            
            while (i < len && nums[i] == last)
                ++i;
            
            bool hasTwo = i >= j + 2;
            nums[next] = last;
            ++next;
            if (hasTwo) {
                nums[next] = last;
                ++next;
            }
        }
        
        return next;
    }
};
