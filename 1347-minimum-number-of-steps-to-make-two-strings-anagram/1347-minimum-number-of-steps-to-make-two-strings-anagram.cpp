class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        vector<int>freq(26,0);
       
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        int count=0;
        for(int i=0; i<n; i++){
            if(freq[t[i]-'a']>0) {
                freq[t[i]-'a']--;
            }
            else count++;


        }
        return count;
    }
};