class Solution {
public:
    bool helper(int n, vector<int>&dp){
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];
        bool moves=false;
        for (int i = 1; i * i <= n; i++) {
            if(helper(n-i*i,dp)==false) return true;
        }
        return dp[n] = moves;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,0);
        if(n==0) return false;
        for(int i=1; i<=n; i++){
            bool moves=false;
            for (int j = 1; j * j <= i; j++) {
                if(dp[i-j*j]==false){
                    moves=true;
                    break;
                }
            }
            dp[i] = moves;
        }
        return dp[n];
    }
};