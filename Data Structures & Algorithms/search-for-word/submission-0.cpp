class Solution {
public:
    bool f(vector<vector<char>>& board, string& word, int row, int col,
           int idx) {
        if (word.size() == idx)
            return true;
        if (row < 0 || col < 0 || row >= board.size() ||
            col >= board[0].size() || board[row][col] != word[idx])
            return false;
        char temp = board[row][col];
        board[row][col] = '#';
        bool found = f(board, word, row + 1, col,idx+1) ||
             f(board, word, row - 1, col, idx+1) ||
             f(board, word, row, col + 1, idx+1) ||
             f(board, word, row, col - 1, idx+1);
        board[row][col] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        string curr = "";
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (f(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};