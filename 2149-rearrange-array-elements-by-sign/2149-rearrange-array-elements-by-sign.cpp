class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>neg;
        vector<int>pos;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }
        int j = 0;
        int k = 0;
        int ind = 0;
        while(ind<n){
            nums[ind] = pos[j];
            j++;
            ind++;
            nums[ind] = neg[k];
            k++;
            ind++;
        }
        return nums;
    }
};