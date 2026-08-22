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
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,1,n,prices,dp);
    }
};