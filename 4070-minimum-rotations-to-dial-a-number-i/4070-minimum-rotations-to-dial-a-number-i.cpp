class Solution {
public:
    int minRotations(string s) {
        int n = s.size();
        int n1 =  0;
        int n2 = s[0]-'0';

        int sum = min(abs(n2-n1), min(n1+9-n2+1, 9-n1+1+n2));
        for(int i=0; i<n-1; i++){
            int num1 = s[i]-'0';
            int num2 = s[i+1]-'0';
            sum += min(abs(num2-num1), min(num1+9-num2+1, 9-num1+1+num2));
        }
        return sum;
    }
};