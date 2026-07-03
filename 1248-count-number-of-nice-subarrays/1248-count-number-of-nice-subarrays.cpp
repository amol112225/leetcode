class Solution {
public:
    int fun(vector<int>&nums, int k){
        if(k<0) return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int count = 0;
        int sum = 0;
        while(r<n){
            sum+=nums[r];

            while(sum>k){
                sum = sum-nums[l];
                l++;
            }
            count+= (r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]&1==1) nums[i] = 1;
            else nums[i] = 0;
        }
        return fun(nums,k) - fun(nums,k-1);
    }
};