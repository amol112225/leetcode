class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int cnt = 2;
            if(word[i]=='c'){
                ans+=cnt;
                continue;
            }
            if(word[i]=='b'){
                if(i+1<n && word[i+1]=='c'){
                    cnt--;
                    i = i+1;
                }
                ans+=cnt;
                continue;
            }
            if(word[i]=='a'){
                if(i+1<n && word[i+1]=='b' || word[i+1]=='c'){
                    cnt--;
                    if(i+2<n && word[i+1]!='c' && word[i+2]=='c'){
                        cnt--;
                        i = i+1;
                    }
                    i = i+1;
                }
                ans+=cnt;
                continue;
            }
        }
        return ans;
    }
};