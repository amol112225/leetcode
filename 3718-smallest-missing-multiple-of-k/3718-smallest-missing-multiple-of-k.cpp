class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int>hash(maxi+1,0);
        for(int j = 0; j<n; j++) hash[nums[j]]++;
        int i=k;
        while(k<=maxi){
            if(hash[k]==0) return k;
            k+=i;
        }
        return k;
    }
};