class Solution {
public:
    int helper(int i, int j, string s1, string s2, vector<vector<int>>&dp){
        if(j<0) return i+1;
        if(i<0) return j+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j] = 0 + helper(i-1,j-1,s1,s2, dp);
        int take1 = 1+helper(i,j-1,s1,s2,dp);
        int take2 = 1+helper(i-1,j,s1,s2,dp);
        int take3 = 1+helper(i-1,j-1,s1,s2,dp);
        return dp[i][j] = min(take1,min(take2,take3));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=0 ;i<=n1; i++) dp[i][0] = i;
        for(int j=0 ;j<=n2; j++) dp[0][j] = j;

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int take1 = 1+dp[i][j-1];
                    int take2 = 1+dp[i-1][j];
                    int take3 = 1+dp[i-1][j-1];
                    dp[i][j] = min(take1,min(take2,take3));
                }
            }
        }
        return dp[n1][n2];

    }
};