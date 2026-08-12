class Solution {
public:
    const long long mod = 1e9 + 7;
    int chota(int n) {
        return 1 << (31 - __builtin_clz(n));
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        int n1 = n;
        while(n1!=0){
            int c = chota(n1);
            powers.push_back(c);
            n1 -=c;
        }
        sort(powers.begin(),powers.end());
        vector<int>ans;
        for(int i=0; i<queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            long long prod = 1;
            for(int j=l; j<=r; j++){
                prod = (prod * powers[j])%mod;
            }
            ans.push_back(prod);
        }
        return ans;

    }
};