class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int row_max[row] = {0};
        int col_max[col] = {0};
        int res = 0;
        for (int i = 0; i < row; ++i) {
            auto &line = grid[i];
            for (int j = 0; j < col; ++j) {
                if (row_max[i] < line[j])
                    row_max[i] = line[j];
                if (col_max[j] < line[j])
                    col_max[j] = line[j];
                res -= line[j];
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j)
                res += min(row_max[i], col_max[j]);
        }
        return res;
    }
};
