class Solution {
public:
    int fun(vector<int>&nums, int k){
        int count = 0;
        int n = nums.size();
        map<int,int>mp;
        int l=0, r=0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};