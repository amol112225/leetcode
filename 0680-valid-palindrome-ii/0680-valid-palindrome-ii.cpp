class Solution {
public:
    bool check(string s, int &l, int &r){
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        bool ans = check(s,l,r);
        int newl = l;
        int newr = r;
        l++;
        ans = ans||check(s,l,r);
        newr--;
        ans = ans||check(s,newl,newr);
        return ans;

    }
};