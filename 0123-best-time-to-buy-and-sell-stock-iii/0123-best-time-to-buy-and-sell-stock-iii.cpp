class Solution {
public:
    int helper(int i, int buy, int n, int cap, vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(i==n || cap==0) return 0;
        
        
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        int profit1 = INT_MIN, profit2 = INT_MIN;

        if(buy==1){
            profit1 = max(-prices[i]+helper(i+1, 0, n, cap, prices, dp), 0 + helper(i+1, 1, n, cap, prices, dp));
        }
        else{
            profit2 = max(prices[i]+helper(i+1, 1, n, cap-1, prices, dp), helper(i+1, 0, n, cap, prices, dp));
        }
        return dp[i][buy][cap] = max(profit1, profit2);

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,1,n,2,prices,dp);
    }
};