class Solution {
public:
    long long totalHours(vector<int>&piles, int mid){
        long long ans = 0;
        for(int i=0; i<piles.size(); i++){
            ans = ans+ceil((double)piles[i]/mid);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;
        
        while(low<=high){
            int mid = (low+high)/2;
            long long th = totalHours(piles,mid);
            if(th <= h) high = mid-1; 
            else low = mid+1;
        }
        return low;
    }
};