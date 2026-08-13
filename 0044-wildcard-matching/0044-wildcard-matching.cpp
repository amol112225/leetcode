class Solution {
public:
    bool helper(int i, int j, string &s, string &p, vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int k=0; k<=j; k++) if(p[k]!='*') return false;
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j] = helper(i-1,j-1,s,p,dp);
        if(p[j]=='*')  return dp[i][j] = helper(i-1,j,s,p,dp) || helper(i,j-1,s,p,dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        dp[0][0] = true;

        for(int i = 1; i <= n1; i++)
            dp[i][0] = false;

        for(int j = 1; j <= n2; j++)
            dp[0][j] = (p[j-1] == '*') && dp[0][j-1];

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*')  dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[n1][n2];
    }
};