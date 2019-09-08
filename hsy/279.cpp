class Solution {
public:
    int numSquares(int n) {
        vector<int> data;
        for (int i = 1; i <= n; ++i) {
            int cnt = sqrt(i);
            if (cnt * cnt == i) {
                data.push_back(1);
                continue;
            }
            int min = data[i - cnt * cnt - 1] + 1;
            for (int j = 1; j < cnt; ++j) {
                int next = data[i - j * j - 1] + 1;
                if (min > next)
                    min = next;
            }
            data.push_back(min);
        }
        return data.back();
    }
};
