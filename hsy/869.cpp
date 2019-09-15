class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<vector<int>> nums;
        for (int i = 0; i < 31; ++i) {
            vector<int> num;
            int data = 1 << i;
            while (data) {
                int n = data % 10;
                data /= 10;
                num.push_back(n);
            }
            sort(num.begin(), num.end());
            nums.push_back(num);
        }
        
        vector<int> target;
        while (N) {
            int n = N % 10;
            N /= 10;
            target.push_back(n);
        }
        sort(target.begin(), target.end());
        
        bool find = false;
        int cnt = target.size();
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (cnt != nums[i].size())
                continue;
            if (target == nums[i]) {
                find = true;
                break;
            }
        }
        
        return find;
    }
};
