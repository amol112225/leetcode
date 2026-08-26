class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int count  = 0;
        string ans = "";
        int strsize = INT_MAX;
        string str = "";
        
        int l=0;
        int r=0;
        while(l<=r && r<n){
            if(s[r]=='1') count++;
            while(count>k){
                if(s[l]=='1') count--;
                l++;
            }
            if(count==k){

                while(l<r && s[l]=='0'){
                    l++;
                }
                int len = r-l+1;
                if(len<strsize){
                    ans = s.substr(l,len);
                    strsize = len;
                    
                }
                else if(len==strsize){
                    if(s.substr(l,len)<ans){
                        ans = s.substr(l,len);
                        strsize = len;
                        
                    }
                }
            }
            // if(count>k){
            //     if(s[l]=='1') count--;
            //     l++;
            // }
            r++;
            
        }
        return ans;
    }
};