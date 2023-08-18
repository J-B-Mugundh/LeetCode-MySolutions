class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> rotten; // <<row, col>, time>
        int vis[n][m], cntFresh = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    rotten.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else vis[i][j] = 0;
                if(grid[i][j] == 1) cntFresh++;
            }
        }
        int tmax = 0, cnt = 0;
        int drow[] = {-1, 0, 0, 1}, dcol[] = {0, 1, -1, 0};
        while(!rotten.empty()){
            int r = rotten.front().first.first;
            int c = rotten.front().first.second;
            int t = rotten.front().second;

            tmax = max(t, tmax);
            rotten.pop();

            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int mcol = c + dcol[i];

                if(nrow >= 0 && nrow < n && mcol >= 0 && mcol < m && vis[nrow][mcol] == 0 && grid[nrow][mcol] == 1){
                    vis[nrow][mcol] = 2;
                    rotten.push({{nrow, mcol}, t + 1});
                    cnt++;
                }
            }
        }

        if(cnt != cntFresh) return -1;
        return tmax;
    }
};