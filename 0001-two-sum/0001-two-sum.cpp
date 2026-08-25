class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<pair<int,int>>arr;
        for(int k=0; k<n; k++) arr.push_back({nums[k], k});
        sort(arr.begin(), arr.end());
        int i=0;
        int j=n-1;
        
        while(i<j){
            int sum = arr[i].first + arr[j].first;
            if(sum>target) j--;
            else if(sum<target) i++;
            
            else{
               return {arr[i].second, arr[j].second};
            }
        }
        return {};
    }
};