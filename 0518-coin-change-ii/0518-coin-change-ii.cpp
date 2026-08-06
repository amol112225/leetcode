class Solution {
public:
int helper(int i, int target, vector<vector<int>>&dp, vector<int>&arr){
        if(i==0){
            if(target % arr[i]==0) return 1;
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notTake = helper(i-1,target,dp,arr);
        int take = 0;
        if(arr[i]<=target){
            take = helper(i,target-arr[i],dp,arr);
        }
        return dp[i][target] = take + notTake;
        
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,dp,coins);
    }
};