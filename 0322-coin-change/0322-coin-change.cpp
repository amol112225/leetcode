class Solution {
public:
    int helper(int i, int target, vector<vector<int>>&dp, vector<int>&arr){
        if(i==0){
            if(target % arr[i]==0) return target/arr[i];
            return 1e9;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notTake = helper(i-1,target,dp,arr);
        int take = INT_MAX;
        if(arr[i]<=target){
            take = 1 + helper(i,target-arr[i],dp,arr);
        }
        return dp[i][target] = min(take,notTake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = helper(n-1,amount,dp,coins);
        if(ans>=1e9) return -1;
        return ans;
    }
};