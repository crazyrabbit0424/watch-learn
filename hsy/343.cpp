class Solution {
public:
    int integerBreak(int n) {
        if (n == 1 || n == 2)
            return 1;
        else if (n == 3)
            return 2;
        
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(2);
        dp.push_back(3);
        for (int i = 4; i <= n; ++i) {
            int max = 0;
            int len = dp.size();
            for (int j = 0; j < len; ++j) {
                int data = (i - j - 1) * dp[j];
                if (max < data)
                    max = data;
            }
            dp.push_back(max);
        }
        
        for (int n : dp) {
            cout << n << " ";
        }
        cout << endl;
        return dp.back();
    }
};
