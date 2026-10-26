class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int r, int c) {
        int n = grid.size();
        int m = grid[0].size();

        long long sum = grid[r][c];
        grid[r][c] = 0;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] > 0) {
                sum += dfs(grid, nr, nc);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(grid, i, j);

                    if (sum % k == 0) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};