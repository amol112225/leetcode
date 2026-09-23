class Solution {
public:
    bool check(vector<int>&arr, long long mid, int thr){
        int temp = 0;
        for(int i=0; i<arr.size(); i++){
            temp+=ceil((double)arr[i]/mid);
        }
        return temp<=thr;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long low = 1;
        long long high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while(low<=high){
            long long mid = (low+high)/2;
            bool is = check(nums,mid,threshold);
            if(is){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};