class Solution {
public:
    bool check(vector<int>& arr, int mid, int k){
        long long sum = 0;
        int cnt = 1;
        for(auto x : arr){
            if(sum+x<=mid){
                sum+=x;
            }
            else{
                sum = x;
                cnt++;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int high = 0;
        for(int i=0; i<n; i++) high+=nums[i];
        int low = *max_element(nums.begin(), nums.end());
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;

            bool is = check(nums, mid, k);
            if(is){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        
        return ans;
        
    }
};