class Solution {
public:
    int setBits(int n){
        int cnt = 0;
        while(n!=0){
            if(n%2==1)cnt++;
            n = n/2;
        }
        return cnt;
    }
    int calculateScore(int a, int b) {
        int s1 = setBits(a);
        int s2 = setBits(b);
        cout<<s1<<" "<<s2;
        if(s1>=s2) return s1*s2;
        return s2/s1;
    }
};