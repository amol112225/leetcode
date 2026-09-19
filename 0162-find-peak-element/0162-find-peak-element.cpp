class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxi = nums[0];
        int ind = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                ind = i;
            }
        }
        return ind;
    }
};