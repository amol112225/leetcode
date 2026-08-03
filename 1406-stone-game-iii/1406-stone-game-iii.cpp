class Solution {
public:
    int helper(int i, vector<int>&dp, vector<int>&values){
        if(i>=values.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int take1=INT_MIN,take2=INT_MIN,take3=INT_MIN;
        take1 = values[i] - helper(i+1,dp,values);
        if(i+1<values.size()) take2 = values[i] + values[i+1] - helper(i+2,dp,values);
        if(i+2<values.size()) take3 = values[i] + values[i+1] + values[i+2] - helper(i+3,dp,values);
        return dp[i] = max(take1,max(take2,take3));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n+1,-1);
        int ans = helper(0,dp,stoneValue);
        if(ans>0) return "Alice";
        else if(ans<0) return "Bob";
        return "Tie";

    }
};