class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int n1 = n;
        while(n!=0){
            int num = n%10;
            sum+=num;
            prod*=num;
            n=n/10;
        }
        return (n1%(sum+prod)==0);
    }
};