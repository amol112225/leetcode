class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        
        for(int i=0; i<n; i++){
            if(grumpy[i]==0) sum+=customers[i];
        }

        int l = 0;
        int r = minutes-1;
        int wsum = 0;
        for(int i=l; i<=r; i++){
           if(grumpy[i] == 1) wsum += customers[i];
        }
        int msum = wsum;
        for(int i=minutes; i<n; i++){
            if(grumpy[i] == 1)
                wsum += customers[i];

            if(grumpy[i-minutes] == 1)
                wsum -= customers[i-minutes];

            if(wsum > msum){
                msum = wsum;
                l = i-minutes+1;
                r = i;
            }
        }

        for(int i=l; i<=r; i++){
            if(grumpy[i]==1) sum+=customers[i];
        }
        return sum;
    }
};