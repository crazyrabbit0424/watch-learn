class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; ++i) {
            auto &line = board[i];
            for (int j = 0; j < col; ++j) {
                int lives = 0;
                if (i > 0) {
                    auto &last = board[i - 1];
                    if (j > 0 && (last[j - 1] & 1))
                        ++lives;
                    if (last[j] & 1)
                        ++lives;
                    if (j < col - 1 && (last[j + 1] & 1))
                        ++lives;
                }
                if (j > 0 && (line[j - 1] & 1))
                    ++lives;
                if (j < col - 1 && (line[j + 1] & 1))
                    ++lives;
                if (i < row - 1) {
                    auto &next = board[i + 1];
                    if (j > 0 && (next[j - 1] & 1))
                        ++lives;
                    if (next[j] & 1)
                        ++lives;
                    if (j < col - 1 && (next[j + 1] & 1))
                        ++lives;
                }
                line[j] += lives << 1;
            }
        }
        
        for (int i = 0; i < row; ++i) {
            auto &line = board[i];
            for (int j = 0; j < col; ++j) {
                int lives = line[j] >> 1;
                if (line[j] & 1) {
                    if (lives < 2 || lives > 3)
                        line[j] = 0;
                    else
                        line[j] = 1;
                } else {
                    if (lives == 3)
                        line[j] = 1;
                    else
                        line[j] = 0;
                }
            }
        }
    }
};
