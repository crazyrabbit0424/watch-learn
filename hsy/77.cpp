class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> vec;
        for (int i = 1; i <= k; ++i)
            vec.push_back(i);
        
        int it = 0;
        while (it < k) {
            if (it == 0) {
                while (vec[k - 1] <= n) {
                    res.push_back(vec);
                    ++vec[k - 1];
                }
                while (it < k && vec[k - 1 - it] >= n - it)
                    ++it;
            } else {
                int last = vec[k - 1 - it];
                for (int i = it; i >= 0; --i) {
                    ++last;
                    vec[k - 1 - i] = last;
                }
                it = 0;
            }
        }
        
        return res;
    }
};
