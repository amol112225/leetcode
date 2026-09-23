class Solution {
public:
    bool check(vector<int>&arr, long long mid, int days){
        int cnt = 1;
        long long temp = 0;
        for(int i=0; i<arr.size(); i++){
    
            if(temp+arr[i] <= mid){
                temp+=arr[i];
            }
            else{
                cnt++;
                temp = arr[i]; 
            }
        }
        return cnt<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        long long high = 0;
        for(int i=0; i<n; i++) high+=weights[i];
        long long low = *max_element(weights.begin(), weights.end());
        long long ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            bool is = check(weights, mid, days);
            if(is){
                ans = mid;
                high = mid-1;
            }

            else low = mid+1;

        }
        return ans;

    }
};