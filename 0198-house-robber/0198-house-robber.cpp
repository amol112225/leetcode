class Solution {
public:
    int helper(int i, vector<int>&dp, vector<int>&nums){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i] + helper(i+2,dp,nums),helper(i+1,dp,nums));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return helper(0,dp,nums);
    }
};