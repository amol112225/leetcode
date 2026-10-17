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

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || v[i].second == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = 1;
                j = v[j].second;
                cycle++;
            }

            cnt += cycle - 1;
        }

        return cnt;
    }
};