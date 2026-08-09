class Solution {
public:
    int helper(int i, int e, int n,vector<int>&totalSum,vector<vector<int>>&dp, vector<int>&piles){
        if(i>=n) return 0;
        if(dp[i][e]!=-1) return dp[i][e];
        int pick = INT_MIN;
        int sum = 0;
        int j=i;
        int cnt=0;
        while(cnt<2*e && j<n){
            cnt++;
            sum+=piles[j];
            pick = max(pick,sum+totalSum[i+cnt]-helper(i+cnt, max(e,cnt), n,totalSum, dp,piles));
            j++;
        }
        return dp[i][e] = pick;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        vector<int> totalSum(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            totalSum[i] = totalSum[i + 1] + piles[i];
        }
        return helper(0,1,n,totalSum,dp,piles);
    }
};