class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if (!len)
            return 0;
        
        set<int> num_set;
        for (int &n : nums)
            num_set.insert(n);
        
        int res = 0;
        int data, cnt;
        bool start = false;
        for (set<int>::iterator I = num_set.begin(), E = num_set.end();
            I != E; ++I) {
            if (!start) {
                data = *I;
                cnt = 1;
                start = true;
            } else if (++data == *I) {
                ++cnt;
            } else {
                if (res < cnt)
                    res = cnt;
                data = *I;
                cnt = 1;
            }
        }
        if (res < cnt)
            res = cnt;
        
        return res;
    }
};
