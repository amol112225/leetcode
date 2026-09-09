class Solution {
public:
    long long countCommas(long long n) {
        long long nalverqito = n;
        long long count = 0;

        if(n >= 1000)
            count += min(n, 999999LL) - 1000 + 1;

        if(n >= 1000000)
            count += 2 * (min(n, 999999999LL) - 1000000 + 1);

        if(n >= 1000000000)
            count += 3 * (min(n, 999999999999LL) - 1000000000 + 1);

        if(n >= 1000000000000LL)
            count += 4 * (min(n, 999999999999999LL) - 1000000000000LL + 1);

        if(n >= 1000000000000000LL)
            count += 5 * (n - 1000000000000000LL + 1);

        return count;
    }
};