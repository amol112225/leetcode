class Solution {
public:
    int reverseDegree(string s) {
        map<char,int>mpp;
        int cnt = 26;
        for(char i='a'; i<='z'; i++){
            mpp[i] = cnt;
            cnt--;
        }
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            ans+=(mpp[s[i]]*(i+1));
        }
        return ans;
    }
};