class Solution {
public:
    int check(string &s, int l, int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;
        string ans = "";
        for(int i=0; i<n; i++){
            int odd = check(s,i,i);
            int even = check(s,i,i+1);
            int len = max(odd,even);

            if(len>(end-start)){
                start = i-(len-1)/2;
                end = i+len/2;
            }
        }
        return s.substr(start,end-start+1);
    }
};