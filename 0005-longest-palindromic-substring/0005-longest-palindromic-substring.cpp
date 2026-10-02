class Solution {
public:
    bool check(string &s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            
            l++;
            r--; 
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++){
           for(int j=i; j<n; j++){
            if(check(s,i,j)){
                if(j-i+1>ans.size()){
                    ans = s.substr(i,j-i+1);
                }
            }
           } 
        }
        return ans;
    }
};