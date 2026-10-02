class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int d = 0;
        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                if(d>0) ans+=s[i];
                d++;
            }
            else{
                d--;
                if(d>0) ans+=s[i];
            }
        }
        return ans;
    }
};