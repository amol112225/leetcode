class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        vector<int>freq(maxi+1,0);
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        vector<int>ans;
        for(int i=mini+1; i<maxi; i++){
            if(freq[i]==0)ans.push_back(i);
        }
        return ans;
    }
};