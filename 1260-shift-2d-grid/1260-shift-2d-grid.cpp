class Solution {
public:
    void helper(vector<vector<int>>& grid, int k, int count, int m, int n) {
        if (count == k) return;

        vector<vector<int>> temp(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == m - 1 && j == n - 1)
                    temp[0][0] = grid[i][j];
                else if (j == n - 1)
                    temp[i + 1][0] = grid[i][j];
                else  
                    temp[i][j + 1] = grid[i][j];
            }
        }

        grid = temp;
        helper(grid, k, count + 1, m, n);
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        helper(grid, k, 0, m, n);
        return grid;
    }
};