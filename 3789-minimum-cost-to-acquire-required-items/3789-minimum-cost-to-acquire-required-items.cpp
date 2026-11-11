class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long ans1 = (long)need1*cost1+(long)need2*cost2;

        long ans2 = (long)max(need1,need2)*costBoth;

        long common = min(need1, need2);

        long ans3 = common*costBoth + (long)(need1-common)*cost1 + (long)(need2-common)*cost2;

        return min(ans1,min(ans2,ans3));


    }
};