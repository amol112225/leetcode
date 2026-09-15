class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n-1; i+=2){
            if(nums[i]!=nums[i-1]) return nums[i-1];
        }
        return nums.back();
    }
};