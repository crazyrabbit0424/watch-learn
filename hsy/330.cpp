class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0;
        if (nums.empty()) {
            nums.push_back(1);
            ++res;
        } else {
            int len = nums.size();
            int last = (nums.back() > n) ? n : nums.back();
            for (int i = 1; i <= last; ++i) {
                int left = i;
                int idx = len - 1;
                //cout << "test " << i << " idx " << idx << endl;
                while (left > 0 && idx >= 0) {
                    if (left >= nums[idx])
                        left -= nums[idx];
                    if (left == 0)
                        break;
                    --idx;
                }

                if (left == 0)
                    continue;
                //cout << "++++ ++++ insert " << i << endl;
                int next = len - 1;
                while (next >= 0 && i < nums[next])
                    --next;
                nums.insert(nums.begin() + next + 1, i);
                ++len;
                ++res;
            }
        }
        unsigned long long total = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
            total += nums[i];
        while (n > total) {
            total += total + 1;
            ++res;
        }
        return res;
    }
};
