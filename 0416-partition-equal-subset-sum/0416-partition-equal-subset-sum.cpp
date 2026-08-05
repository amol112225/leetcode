class Solution {
public:
    bool helper(int i, int target, int n, vector<vector<int>>&dp, vector<int>&nums){
        if(target==0) return true;
        if(i==n-1) return (nums[i]==target);
        if(dp[i][target]!=-1) return dp[i][target];
        bool notTake = helper(i+1,target,n,dp,nums);
        bool take = false;
        if(target>=nums[i]){
            take = helper(i+1,target-nums[i],n,dp,nums);
        }
        return dp[i][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2!=0) return false;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return helper(0,sum/2,n,dp,nums);

    }
};