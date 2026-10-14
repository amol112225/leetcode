class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(sum>1LL*9*num) return ans;
        while(num>0){
            if(sum-9>=0){
                ans+='9';
                sum-=9;
            }
            else if(sum-9<0){
                ans+=to_string(sum);
                sum=0;
            }
            else{
                ans+='0';
            }
            num--;
        }
        return ans;


    }
};