class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        int l = 0;
        int r = n-1;

        while(l<=r){
            if(((tolower(s[l])>=48 && tolower(s[l])<=57)||(tolower(s[l])>=97 && tolower(s[l])<=122)) && 
            ((tolower(s[r])>=48 && tolower(s[r])<=57||tolower(s[r])>=97 && tolower(s[r])<=122))){
                if(tolower(s[l])!=tolower(s[r])) return false;
                else{
                    l++;
                    r--;
                    continue;
                }
            }
            if((tolower(s[l])>57 ||tolower(s[l])<48) && (tolower(s[l])<97 || tolower(s[l])>122)) l++;
            if((tolower(s[r])>57 || tolower(s[r])<48) && (tolower(s[r])<97 ||tolower(s[r])>122)) r--;


        }
        return true;
    }
};