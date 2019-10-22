class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> imap;
        for (auto &line : wall) {
            int idx = 0;
            int len = line.size() - 1;
            for (int i = 0; i < len; ++i) {
                idx += line[i];
                ++imap[idx];
            }
        }
        
        int res = 0;
        for (auto &p : imap) {
            if (res < p.second)
                res = p.second;
        }
        return wall.size() - res;
    }
};
