class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = board.size();
        int col = board[0].size();
        int x = click[0];
        int y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        
        int mines = 0;
        if (x > 0) {
            if (y > 0 && board[x - 1][y - 1] == 'M')
                ++mines;
            if (board[x - 1][y] == 'M')
                ++mines;
            if (y < col - 1 && board[x - 1][y + 1] == 'M')
                ++mines;
        }
        if (y > 0 && board[x][y - 1] == 'M')
            ++mines;
        if (y < col - 1 && board[x][y + 1] == 'M')
            ++mines;
        if (x < row - 1) {
            if (y > 0 && board[x + 1][y - 1] == 'M')
                ++mines;
            if (board[x + 1][y] == 'M')
                ++mines;
            if (y < col - 1 && board[x + 1][y + 1] == 'M')
                ++mines;
        }
        
        if (mines != 0) {
            board[x][y] = '0' + mines;
            return board;
        }
        
        board[x][y] = 'B';
        if (x > 0) {
            if (y > 0 && board[x - 1][y - 1] == 'E') {
                vector<int> next;
                next.push_back(x - 1);
                next.push_back(y - 1);
                updateBoard(board, next);
            }
            if (board[x - 1][y] == 'E') {
                vector<int> next;
                next.push_back(x - 1);
                next.push_back(y);
                updateBoard(board, next);
            }
            if (y < col - 1 && board[x - 1][y + 1] == 'E') {
                vector<int> next;
                next.push_back(x - 1);
                next.push_back(y + 1);
                updateBoard(board, next);
            }
        }
        if (y > 0 && board[x][y - 1] == 'E') {
            vector<int> next;
            next.push_back(x);
            next.push_back(y - 1);
            updateBoard(board, next);
        }
        if (y < col - 1 && board[x][y + 1] == 'E') {
            vector<int> next;
            next.push_back(x);
            next.push_back(y + 1);
            updateBoard(board, next);
        }
        if (x < row - 1) {
            if (y > 0 && board[x + 1][y - 1] == 'E') {
                vector<int> next;
                next.push_back(x + 1);
                next.push_back(y - 1);
                updateBoard(board, next);
            }
            if (board[x + 1][y] == 'E') {
                vector<int> next;
                next.push_back(x + 1);
                next.push_back(y);
                updateBoard(board, next);
            }
            if (y < col - 1 && board[x + 1][y + 1] == 'E') {
                vector<int> next;
                next.push_back(x + 1);
                next.push_back(y + 1);
                updateBoard(board, next);
            }
        }
        
        return board;
    }
};
