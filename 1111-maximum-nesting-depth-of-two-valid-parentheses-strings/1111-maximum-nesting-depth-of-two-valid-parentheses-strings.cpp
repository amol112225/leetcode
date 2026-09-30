class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n);
        int d = 0;
        for(int i=0; i<n; i++){
            if(seq[i]=='('){
                d++;
            } 
            if(d%2==0) ans[i]=1;
            else ans[i]=0;

            if(seq[i]==')') d--;

        }
        return ans;
    }
};