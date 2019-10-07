class Solution {
private:
    map<int, int> dmap;
    int row;
    int col;
    int res;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix, int x, int y) {
        int val = matrix[x][y];
        int max = 1;
        if (x > 0 && matrix[x - 1][y] > val) {
            int path = 0;
            if (dmap.count((x - 1) << 16 | y))
                path = dmap[(x - 1) << 16 | y] + 1;
            else
                path = longestIncreasingPath(matrix, x - 1, y) + 1;
            if (max < path)
                max = path;
        }
        if (y < col - 1 && matrix[x][y + 1] > val) {
            int path = 0;
            if (dmap.count(x << 16 | (y + 1)))
                path = dmap[x << 16 | (y + 1)] + 1;
            else
                path = longestIncreasingPath(matrix, x, y + 1) + 1;
            if (max < path)
                max = path;
        }
        if (x < row - 1 && matrix[x + 1][y] > val) {
            int path = 0;
            if (dmap.count((x + 1) << 16 | y))
                path = dmap[(x + 1) << 16 | y] + 1;
            else
                path = longestIncreasingPath(matrix, x + 1, y) + 1;
            if (max < path)
                max = path;
        }
        if (y > 0 && matrix[x][y - 1] > val) {
            int path = 0;
            if (dmap.count(x << 16 | (y - 1)))
                path = dmap[x << 16 | (y - 1)] + 1;
            else
                path = longestIncreasingPath(matrix, x, y - 1) + 1;
            if (max < path)
                max = path;
        }
        dmap[x << 16 | y] = max;
        //cout << "x: " << x << " y: " << y << " " << max << endl;
        if (res < max)
            res = max;
        return max;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        res = 0;
        row = matrix.size();
        if (row == 0)
            return 0;
        col = matrix[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                longestIncreasingPath(matrix, i, j);
            }
        }
        return res;
    }
};
