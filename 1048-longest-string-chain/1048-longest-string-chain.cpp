class Solution {
public:
    bool check(string s1, string s2){
        if(s1.size()+1!=s2.size()) return false;
        int i=0, j=0;
        
        while(i<s1.size() && j<s2.size()){
            if(s1[i]!=s2[j]){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        if(i==s1.size()) return true;
        return false;
    }
    static bool comp(const string &s1, const string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n  = words.size();
        vector<int>dp(n,1);
        int maxi = 1;
        sort(words.begin(), words.end(), comp);
        for(int i=1; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(check(words[prev], words[i]) && dp[prev]+1>dp[i]){
                    dp[i] = dp[prev]+1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};