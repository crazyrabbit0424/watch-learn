class Solution {
public:
    void calcIsland(vector<vector<int>> &grid, set<int> &island, int x, int y) {
        island.insert(x << 16 | y);
        grid[x][y] = 0;
        if (x > 0 && grid[x - 1][y])
            calcIsland(grid, island, x - 1, y);
        if (y > 0 && grid[x][y - 1])
            calcIsland(grid, island, x, y - 1);
        if (x + 1 < grid.size() && grid[x + 1][y])
            calcIsland(grid, island, x + 1, y);
        if (y + 1 < grid[0].size() && grid[x][y + 1])
            calcIsland(grid, island, x, y + 1);
        return;
    }
    int findConnect(vector<set<int>> &islands, int x, int y) {
        int pos = x << 16 | y;
        for (int i = 0; i < islands.size(); ++i) {
            auto &s = islands[i];
            if (s.count(pos))
                return i;
        }
        return -1;
    }
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<int>> bakgrid = grid;
        int row = grid.size();
        int col = grid[0].size();
        vector<set<int>> islands;
        for (int i = 0; i < row; ++i) {
            auto &line = grid[i];
            for (int j = 0; j < col; ++j) {
                if (line[j] == 0)
                    continue;
                set<int> island;
                calcIsland(grid, island, i, j);
                islands.push_back(island);
            }
        }
        for (auto &s : islands) {
            cout << s.size() << " ";
            if (s.size() == 1)
                cout << "(" << (*s.begin() >> 16) << ", " << (*s.begin() & 0xFF) << ") ";
        }
        cout << endl;
        int max = 0;
        if (islands.empty())
            return 1;
        if (islands.size() == 1) {
            max = islands[0].size();
            if (max == row * col)
                return max;
            else
                return max + 1;
        }
        for (int i = 0; i < row; ++i) {
            auto &line = bakgrid[i];
            for (int j = 0; j < col; ++j) {
                if (line[j] == 1)
                    continue;
                set<int> iset;
                if (i > 0 && bakgrid[i - 1][j])
                    iset.insert(findConnect(islands, i - 1, j));
                if (j > 0 && bakgrid[i][j - 1])
                    iset.insert(findConnect(islands, i, j - 1));
                if (i + 1 < row && bakgrid[i + 1][j])
                    iset.insert(findConnect(islands, i + 1, j));
                if (j + 1 < col && bakgrid[i][j + 1])
                    iset.insert(findConnect(islands, i, j + 1));
                int cnt = 1;
                for (int n : iset)
                    cnt += islands[n].size();
                if (max < cnt)
                    max = cnt;
            }
        }
        return max;
    }
};
