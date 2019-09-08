class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        
        vector<int> res;
        res.push_back(1);
        res.push_back(2);
        for (int i = 2; i < n; ++i) {
            int n = res[i - 1] + res[i - 2];
            res.push_back(n);
        }
        
        return res.back();
    }
};
