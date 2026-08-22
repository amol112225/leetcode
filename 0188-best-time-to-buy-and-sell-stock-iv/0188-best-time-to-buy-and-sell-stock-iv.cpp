class Solution {
public:
    int helper(int i, int buy, int cap, int n, vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(i==n || cap==0) return 0;

        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        int profit1 = INT_MIN, profit2 = INT_MIN;

        if(buy==1){
            profit1 = max(-prices[i] + helper(i+1, 0, cap, n, prices, dp), 0 + helper(i+1, 1, cap, n, prices, dp));
        }
        else{
            profit2 = max(prices[i] + helper(i+1, 1, cap-1, n, prices, dp), helper(i+1, 0, cap, n, prices, dp));
        }
        return dp[i][buy][cap] = max(profit1, profit2);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(0,1,k,n,prices,dp);
    }
};