class Solution {
public:
int helper(int i, int target, vector<vector<int>>&dp, vector<int>&arr){
        if(i==0){
            if(target==0 && arr[0]==0) return 2;
            if(target==0 || target==arr[0]) return 1;
            return 0;
        }
        if(i==0) return (arr[i]==target);
        if(dp[i][target]!=-1) return dp[i][target];
        int notTake = helper(i-1,target,dp,arr);
        int take = 0;
        if(arr[i]<=target){
            take = helper(i-1,target-arr[i],dp,arr);
        }
        return dp[i][target] = (take + notTake);

    }
    int findTargetSumWays(vector<int>& nums, int diff) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum+=nums[i];
        int target = (sum-diff)/2;
        if((sum-diff)<0 || (sum-diff)%2) return 0;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return helper(n-1,target,dp,nums);
        
    }
};