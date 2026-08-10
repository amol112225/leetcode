class Solution {
public:
    int nextSum(int i,int k, vector<int>&code, int n){
        int sum = 0;
        i=(i+1)%n;
        while(k!=0){
            sum+=code[i];
            i=(i+1)%n;
            k--;
        }
        return sum;
    }
    int prevSum(int i, int k, vector<int>&code, int n){
        int sum = 0;
        i = (i-1+n)%n;
        while(k!=0){
            sum+=code[i];
            i=(i-1+n)%n;
            k++;
        }
        return sum;
    }
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans(n,0);
        if(k>0){
            for(int i=0; i<n; i++){
                ans[i] = nextSum(i,k,code,n);
            }
            return ans;
        }
        else if(k<0){
            for(int i=0; i<n;  i++){
                ans[i] = prevSum(i,k,code,n);
            }
        }
        return ans;
    }
};