class Solution {
public:
    int helper(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&triangle, int m){
        if(i==m-1) return triangle[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int take1 = triangle[i][j] + helper(i+1,j,dp,triangle,m);
        int take2 = triangle[i][j] + helper(i+1,j+1,dp,triangle,m);
        return dp[i][j] = min(take1,take2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,INT_MAX));
        return helper(0,0,dp,triangle,m);

    }
};