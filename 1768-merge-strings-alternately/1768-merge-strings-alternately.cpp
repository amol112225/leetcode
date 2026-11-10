class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i1 = 0;
        int i2 = 0;
        int n1 = word1.size();
        int n2 = word2.size();
        string word = "";
        while(i1<n1 && i2<n2){
            word+=word1[i1];
            i1++;
            word+=word2[i2];
            i2++;
        }
        while(i1<n1){
            word+=word1[i1];
            i1++;
        }
        while(i2<n2){
            word+=word2[i2];
            i2++;
        }
        return word;
    }
};