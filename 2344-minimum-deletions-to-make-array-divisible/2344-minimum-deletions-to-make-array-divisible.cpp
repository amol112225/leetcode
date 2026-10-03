class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n1 = nums.size();
        int n2 = numsDivide.size();
        int num = -1;
        int cnt = 0;
        vector<int>copy(nums.begin(), nums.end());
        while(!nums.empty()){
            int mini = *min_element(nums.begin(), nums.end());
           
            for(int j=0; j<n2; j++){
                if(numsDivide[j]%mini==0){
                    num = mini;
                }
                else{
                    num=-1;
                    break;
                }
               
            }
           
            if(num==-1){
                nums.erase(remove(nums.begin(), nums.end(), mini), nums.end());
            }
            else break;
        }
    
        if(num==-1) return -1;
        for(int i=0; i<n1; i++){
            if(copy[i]<num) cnt++;
        }
        return cnt;


    }
};