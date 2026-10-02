class Solution {
public:
    pair<int,int> mostAndLeast(string &s, int l, int r){
        vector<int>freq(26,0);

        for(int i=l; i<=r; i++){
            freq[s[i]-'a']++;
        }
        int least = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) least = min(least, freq[i]);
        }
        int most = *max_element(freq.begin(), freq.end());
        return {most,least};
    }
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0; i<n;i++){
            for(int j=i; j<n; j++){
                auto ans = mostAndLeast(s,i,j);
                sum+=(ans.first-ans.second);
            }
        }
        return sum;
    }
};