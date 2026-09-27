class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mpp;
        vector<int>ans;
        for(auto i : nums){
            mpp[i]++;
        }
        while(n>0){
            for(auto &it : mpp){
                if(it.second>0){
                    ans.push_back(it.first);
                    it.second--;
                    n--;
                }
            }
        }
        return ans;
    }
};