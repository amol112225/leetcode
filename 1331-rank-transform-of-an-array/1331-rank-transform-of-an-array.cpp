class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {}; 
        vector<int>arr1=arr;
        sort(arr.begin(),arr.end());
        map<int,int>mp;
        mp[arr[0]]=1;
        int count=2;
        for(int i=1; i<arr.size(); i++){
            if(arr[i]==arr[i-1]){
                mp[arr[i]]=mp[arr[i-1]];
            }
            else{
                mp[arr[i]]=count;
                count++;
            }
        }
        vector<int>result;
        for(int i=0; i<arr1.size(); i++){
            result.push_back(mp[arr1[i]]);
        }
        return result;

    }
};