class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n = n1+n2;
        int i=0, j=0;
        vector<int>arr;
        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j]) arr.push_back(arr1[i++]);
            else arr.push_back(arr2[j++]);
        }
        while(i<n1) arr.push_back(arr1[i++]);
        while(j<n2) arr.push_back(arr2[j++]);
        double ans = 0;
        if(n%2!=0) ans = arr[n/2];
        else ans = ((double)arr[n/2]+arr[(n/2)-1])/2;
       return ans;
    }
};