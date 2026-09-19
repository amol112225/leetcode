class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int i=0;
        int j=n-1;
        
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum>target) j--;
            else if(sum<target) i++;
            
            else{
               return {i,j};
            }
        }
        return {};
    }
};