class Solution {
public:
    vector<vector<int>> getValidCombination(int k, int n, int start) {
        vector<vector<int>> combine;
        if (k == 1) {
            if (n >= start && n < 10) {
                vector<int> v = {n};
                combine.push_back(v);
            }
            return combine;
        }
        
        for (int i = start; i <= (10 - k); ++i) {
            vector<vector<int>> sub = getValidCombination(k - 1, n - i, i + 1);
            if (sub.size()) {
                for (auto &s : sub) {
                    s.push_back(i);
                }
                combine.insert(combine.begin(), sub.begin(), sub.end());
            }
        }
        return combine;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combine;
        combine = getValidCombination(k, n, 1);
        return combine;
    }
};
