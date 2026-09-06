class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            set<int> s(nums.begin(), nums.end());
            return vector<int>(s.begin(), s.end());
        }

        sort(nums.begin(), nums.end());

        vector<int> ans;
        int curr = nums[0];
        int cnt = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] == curr) {
                cnt++;
            }
            else {
                if(cnt > n/3)
                    ans.push_back(curr);

                curr = nums[i];
                cnt = 1;
            }
        }

        
        if(cnt > n/3)
            ans.push_back(curr);

        return ans;
    }
};