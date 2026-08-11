class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>freq;
        
        long long sum = 0;
        int dcount=0;
        for(int i=0; i<k; i++){
            if(freq[nums[i]]==1) dcount++;
            freq[nums[i]]++;
            sum+=nums[i];
        }
        
        long long ans = 0;
        int i=0;
        int j = k;
        if(dcount==0) ans = sum;
        while(i<n-k && j<n){
            freq[nums[i]]--;
            if(freq[nums[i]]==1) dcount--;
            if(freq[nums[j]]==1) dcount++;
            freq[nums[j]]++;
            sum = sum-nums[i]+nums[j];
            if(dcount==0){
                ans = max(ans,sum);
            }
            i++;
            j++;
        }
        return ans;
    }
};