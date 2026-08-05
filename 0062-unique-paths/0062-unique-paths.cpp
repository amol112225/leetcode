class Solution {
public:
    int helper(int i, int j, vector<vector<int>>&dp, int m, int n){
        if(i==m-1 && j==n-1) return 1;
        if(i>m-1 || j>n-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = helper(i,j+1, dp,m,n);
        int bottom = helper(i+1,j,dp,m,n);
        return dp[i][j] = right+bottom;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,dp,m,n);
    }
};