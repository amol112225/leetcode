class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxi = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                cnt++;
                maxi = max(cnt,maxi);
            }
            if(s[i]==')')cnt--;
        }
        return maxi;
    }
};