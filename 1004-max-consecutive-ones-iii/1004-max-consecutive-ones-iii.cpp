class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        int zeros = 0;
        int l=0, r=0;

        while(r<n){
            if(nums[r]==0) zeros++;
            if(zeros<=k){
                int len = r-l+1;
                maxlen = max(maxlen,len);
            }
            else{
                while(nums[l]!=0){
                    l++;
                }
                l++;
                zeros--;
            }
            r++;
        }
        return maxlen;
    }
};