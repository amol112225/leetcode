class Solution {
public:
int minDeletionSize(vector<string>& strs) {
int n = strs.size();
int cnt = 0;

    int n1 = strs[0].size();
    bool flag = true;
    for(int i=0; i<n1; i++){
        
        for(int j=0; j<n-1; j++){
            if(strs[j][i]>strs[j+1][i]){
                cnt++;
                break;
            }
            
        }
    }
    return cnt;
}

};