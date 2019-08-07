class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int cnt = nums.size();
        if (!cnt)
            return 0;

        int *lenI = new int[cnt];
        int max = 1;
        for (int i = 0; i < cnt; ++i) {
            int maxI = 1;
            for (int j = 0; j < i; ++j) {
                if ((nums[j] < nums[i]) && (lenI[j] >= maxI))
                    maxI = lenI[j] + 1;
            }
            lenI[i] = maxI;
            max = max > maxI ? max : maxI;
        }

        delete[] lenI;
        return max;
    }
};
