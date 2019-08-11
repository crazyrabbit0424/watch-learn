class Solution{
    public:
    int lengthOfLIS(vector<int> &nums){
        if (0 == nums.size())
        {
            return 0;
        }

        vector<int> tmpVector(nums.size() + 1, 0);
        tmpVector[1] = nums[0];
        int maxlen = 1;
        int left = 1;
        int right = maxlen;
        int mid = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            left = 1;
            right = maxlen;

            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (tmpVector[mid] < nums[i])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            tmpVector[left] = nums[i];
            if (left > maxlen)
            {
                maxlen = left;
            }
        }
        return maxlen;
    }
}
