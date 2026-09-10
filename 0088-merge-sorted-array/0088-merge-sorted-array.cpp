class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans(nums1.begin(), nums1.end());
        int k = 0;
        for(int i=m; i<m+n; i++){
            ans[i] = nums2[k];
            k++;
        }
        sort(ans.begin(), ans.end());
        nums1 = ans;
    }
};