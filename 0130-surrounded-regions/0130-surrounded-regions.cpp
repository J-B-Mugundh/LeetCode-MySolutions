class Solution {
private:
    void dfs(int r, int c, int n, int m, vector<vector<char>>& board){
        if(r < 0 || c < 0 || r >= n || c >= m || board[r][c] != 'O')
            return ;
        
        board[r][c] = 'T';
        dfs(r - 1, c, n, m, board);
        dfs(r + 1, c, n, m, board);
        dfs(r, c - 1, n, m, board);
        dfs(r, c + 1, n, m, board);
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        // Capture the unsurrounded regions (O -> T)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
                    dfs(i, j, n, m, board);
            }
        }

        // Capture the surrounded regions (O -> X)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        // Capture the surrounded regions (O -> X)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        // Un capture the unsurrounded regions (T -> O)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};