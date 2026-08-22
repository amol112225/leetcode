class Solution {
public:
    int helper(int i, int buy, int n,vector<int>&prices, vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit1 = INT_MIN, profit2 = INT_MIN;

        if(buy==1){
            profit1 = max(-prices[i] + helper(i+1, 0, n, prices, dp), 0 + helper(i+1,1,n,prices, dp));
        }
        else{
            profit2 = max(prices[i]+helper(i+1,1,n,prices,dp), helper(i+1,0,n,prices,dp));
        }
        return dp[i][buy] = max(profit1,profit2);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,0));
        for(int j=0; j<2; j++) dp[n][j] = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                int profit1 = INT_MIN, profit2 = INT_MIN;

                if(j==1){
                    profit1 = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                }
                else{
                    profit2 = max(prices[i]+dp[i+1][1], dp[i+1][0]);
                }
                dp[i][j] = max(profit1,profit2);
            }
        }
        return dp[0][1];
    }
};