class Solution {
public:
    bool check(vector<int>&arr, int mid, int m, int k){
        int cnt = 0;
        int temp = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] <= mid) {
                temp++;
                if(temp == k) {
                    cnt++;
                    temp = 0;
                }
            }
            else {
                temp = 0;
            }
        }
        return cnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low = 1;
        int ans = -1;
        
        while(low<=high){
            int mid = (low+high)/2;
            bool is = check(bloomDay,mid,m,k);
            if(is){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};