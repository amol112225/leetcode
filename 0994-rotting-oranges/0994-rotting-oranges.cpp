class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        queue<pair<pair<int,int>,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    visited[i][j]=2;
                    q.push({{i,j},0});
                }
            }
        }
        int t=0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            t = max(t,time);
            for(int i=0; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    grid[nrow][ncol]==1 && visited[nrow][ncol]!=2){
                        q.push({{nrow,ncol},time+1});
                        grid[nrow][ncol]=2;
                        visited[nrow][ncol]=2;
                    }
            }

        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]!=2) return -1;
            }
        }
        return t;

    
    }
};