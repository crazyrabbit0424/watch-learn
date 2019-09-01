class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        int size = (nums.size() + 31) / 32;
        int *ps = new int[size];
        memset(ps, 0, size * 4);
        for (int n : nums) {
            int idx = n / 32;
            int bits = n % 32;
            if (ps[idx] & (1 << bits))
                res = n;
            else
                ps[idx] |= 1 << bits;
        }
        delete[] ps;
        return res;
    }
};
