class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int cnt = 0;
        int n1 = strs[0].size();
        vector<bool>sorted(n-1,false);
        for(int i=0; i<n1; i++){
            bool bad = false;
            for(int j=0; j<n-1; j++){
                if(!sorted[j] && strs[j][i]>strs[j+1][i]){
                    bad = true;
                    break;
                }
            }
            if(bad){
                cnt++;
                continue;
            }

            for(int j=0; j<n-1; j++){
                if(strs[j][i]<strs[j+1][i]){
                    sorted[j]=true;
                }
               
            }
        }
        return cnt;
    }
};