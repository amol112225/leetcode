class Solution {
public:
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
    vector<int>findnle(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
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
    vector<int>findple(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;

    }
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int>pse;
        vector<int>nse;
        pse = findpse(arr);
        nse = findnse(arr);

        vector<int>ple;
        vector<int>nle;
        ple = findple(arr);
        nle = findnle(arr);
        long long sum1 = 0;
        long long sum2 = 0;
        for(int i=0; i<n; i++){
            int l = i-pse[i];
            int r = nse[i]-i;
            sum1 = (sum1 + 1LL*l*r*arr[i]);
        }
        for(int i=0; i<n; i++){
            int l = i-ple[i];
            int r = nle[i]-i;
            sum2 = (sum2 + 1LL*l*r*arr[i]);
        }
        return sum2-sum1;
    }
};