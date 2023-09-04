class Solution {
private:
    void dfs(int r, int c, int n, int m, vector<vector<char>> &grid){
        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '0')
            return;
        
        grid[r][c] = '0';

        dfs(r + 1, c, n, m, grid);
        dfs(r - 1, c, n, m, grid);
        dfs(r, c - 1, n, m, grid);
        dfs(r, c + 1, n, m, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int num_islands = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    num_islands++;
                    dfs(i, j, n, m, grid);
                }
            }
        }

        return num_islands;
    }
};