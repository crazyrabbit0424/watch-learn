class Solution {
private:
    int row;
    int col;
public:
    void dfs(vector<vector<int>>& A, int x, int y) {
        A[x][y] = 2;
        if (x > 0 && A[x - 1][y] == 1)
            dfs(A, x - 1, y);
        if (y > 0 && A[x][y - 1] == 1)
            dfs(A, x, y - 1);
        if (x + 1 < row && A[x + 1][y] == 1)
            dfs(A, x + 1, y);
        if (y + 1 < col && A[x][y + 1] == 1)
            dfs(A, x, y + 1);
    }
    int numEnclaves(vector<vector<int>>& A) {
        row = A.size();
        col = A[0].size();
        for (int i = 0; i < col; ++i) {
            if (A[0][i] == 1)
                dfs(A, 0, i);
            if (A[row - 1][i] == 1)
                dfs(A, row - 1, i);
        }
        cout << "1" << endl;
        for (int i = 0; i < row; ++i) {
            if (A[i][0] == 1)
                dfs(A, i, 0);
            if (A[i][col - 1] == 1)
                dfs(A, i, col - 1);
        }
        cout << "2" << endl;
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (A[i][j] == 1)
                    ++res;
            }
        }
        return res;
    }
};
