class Solution {
public:
    void generate(int num, int digit, vector<int>& ans, int low, int high) {

        if (num >= low && num <= high) ans.push_back(num);
        int divisor = pow(10, digit - 1);
        int lastDigit = num % 10;
        if (lastDigit != 9) {
            int newNumber = (num % divisor) * 10 + (lastDigit + 1);
            if (newNumber <= high) generate(newNumber, digit, ans, low, high);
        }
    }

    vector<int> sequentialDigits(int low, int high) {
        int originalLow = low;
        int digit = 0;
        while (low!=0) {
            digit++;
            low = low/10;
        }

        int num = 1;
        for (int i = 2; i <= digit; i++) {
            num = num * 10 + i;
        }

        vector<int> ans;
        generate(num, digit, ans, originalLow, high);
        while (digit < 9) {
            digit++;
            num = num * 10 + digit;
            generate(num, digit, ans, originalLow, high);
        }

        return ans;
    }
};