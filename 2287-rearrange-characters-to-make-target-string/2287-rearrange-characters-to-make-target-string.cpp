class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int n1 = s.size();
        int n2 = target.size();
        map<char,int>mpp;
        for(int i=0;i<n2; i++){
            mpp[target[i]] = 0;
        }
        for(int i=0;i<n1; i++){
            if(mpp.find(s[i])!=mpp.end()) mpp[s[i]]++;
        }

        int cnt = 0;
        while(1){
            for(int i=0; i<n2; i++){
                if(mpp[target[i]]==0) return cnt;
                else{
                    mpp[target[i]]--;
                }
            }
            cnt++;
        }
        return cnt;
    }
};