class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>freq;
        int maxi = 0;
        int i=0;
        for(int j=0; j<n; j++){
            freq[nums[j]]++;
            while(freq[nums[j]]>k){
                freq[nums[i]]--;
                i++;
            }
            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
};