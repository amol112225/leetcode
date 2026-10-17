class Solution {
public:
    int sum(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({{sum(nums[i]), nums[i]}, i});
        }

        sort(v.begin(), v.end());
        int cnt = 0;
        int idx =0;
        while(idx < n){
         if(v[idx].second == idx) idx++;
         else{
            int a = v[idx].second;
            swap(v[idx], v[a]);
            cnt++;
            }
         }
         return cnt;
    }
};