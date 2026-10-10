class Solution {
public:
    int mod = (int) 1e9+7;
    vector<int>findnse(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;

    }
    vector<int>findpse(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;

    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>pse;
        pse = findpse(arr);
        vector<int>nse;
        nse = findnse(arr);
        int sum = 0;
        for(int i=0; i<n; i++){
            int l = i-pse[i];
            int r = nse[i]-i;
            sum = (sum + (1LL*l*r*arr[i])%mod)%mod;
        }
        return sum;
    }
};