class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        int hash[256] = {0};

        for (int i = 0; i < m; i++)
            hash[t[i]]++;

        int l = 0, r = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = -1;

        while (r < n) {

            if (hash[s[r]] > 0)
                count++;

            hash[s[r]]--;

            while (count == m) {

                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                hash[s[l]]++;

                if (hash[s[l]] > 0)
                    count--;

                l++;
            }

            r++;
        }

        if (start == -1)
            return "";

        return s.substr(start, minLen);
    }
};