class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int *path = new int[row * col];
        int sum = 0;
        vector<int> &first = grid[0];
        for (int i = 0; i < col; ++i) {
            sum += first[i];
            path[i] = sum;
        }
        
        for (int i = 1; i < row; ++i) {
            vector<int> &next = grid[i];
            int *next_path = path + i * col;
            next_path[0] = next_path[-col] + next[0];
            for (int j = 1; j < col; ++j) {
                next_path[j] = ((next_path[j - 1] > next_path[j - col]) ? next_path[j - col] : next_path[j - 1]) + next[j];
            }
        }
        
        int res = path[row * col - 1];
        delete[] path;
        return res;
    }
};
