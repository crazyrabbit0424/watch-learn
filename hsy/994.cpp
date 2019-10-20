class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        set<pair<int, int>> rot;
        set<pair<int, int>> fresh;
        
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            vector<int> &one_row = grid[i];
            for (int j = 0; j < col; ++j) {
                if (one_row[j] == 1)
                    fresh.insert({i, j});
                if (one_row[j] == 2)
                    rot.insert({i, j});
            }
        }
        
        int times = 0;
        while (!fresh.empty()) {
            ++times;
            bool changed = false;
            set<pair<int, int>> last = rot;
            for (auto &n : last) {
                if (n.first) {
                    pair<int, int> next = {n.first - 1, n.second};
                    if (fresh.count(next)) {
                        fresh.erase(next);
                        rot.insert(next);
                        changed = true;
                    }
                }
                if (n.second) {
                    pair<int, int> next = {n.first, n.second - 1};
                    if (fresh.count(next)) {
                        fresh.erase(next);
                        rot.insert(next);
                        changed = true;
                    }
                }
                if (n.second < col - 1) {
                    pair<int, int> next = {n.first, n.second + 1};
                    if (fresh.count(next)) {
                        fresh.erase(next);
                        rot.insert(next);
                        changed = true;
                    }
                }
                if (n.first < row - 1) {
                    pair<int, int> next = {n.first + 1, n.second};
                    if (fresh.count(next)) {
                        fresh.erase(next);
                        rot.insert(next);
                        changed = true;
                    }
                }
            }
            if (!changed)
                break;
        }
        
        if (fresh.empty())
            return times;
        else
            return -1;
    }
};
