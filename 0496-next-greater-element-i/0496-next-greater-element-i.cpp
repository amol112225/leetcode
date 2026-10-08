class Solution {
public:
    int check(int x, vector<int>&nums){
        int j=0;
        while(nums[j]!=x) j++;
        for(int i=j; i<nums.size(); i++){
            if(nums[i]>x) return nums[i];
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int>ans(n1);
        for(int i=0; i<n1; i++){
            ans[i] = check(nums1[i], nums2);
        }
        return ans;
    }
};