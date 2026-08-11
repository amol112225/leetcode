class Solution {
public:
    int minSteps(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i=0; i<n1; i++){
            freq1[s[i]-'a']++;
        }
        for(int i=0; i<n2; i++){
            freq2[t[i]-'a']++;
        }
        int count=0;
        for(int i=0; i<26; i++){
            count += abs(freq1[i]-freq2[i]);
        }
        return count;
    }
};