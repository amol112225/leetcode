class Solution {
public:
    void dfs(vector<vector<int>>&grid, int r, int c){
        grid[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        vector<int>dr = {-1,0,1,0};
        vector<int>dc = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0) dfs(grid,nr,nc);
            
        }

    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            if(grid[i][0]==0) dfs(grid,i,0);
            if(grid[i][m-1]==0) dfs(grid,i,m-1);
        }
        for(int j=0; j<m; j++){
            if(grid[0][j]==0) dfs(grid,0,j);
            if(grid[n-1][j]==0) dfs(grid,n-1,j);
        }

        int cnt = 0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j]==0){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
        
    }
};