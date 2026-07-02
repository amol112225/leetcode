class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxc=0; 
        int current_count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                current_count++;
                maxc=max(current_count,maxc);
            }
            else{
                current_count=0;
            }
        }
        return maxc;
    }
};