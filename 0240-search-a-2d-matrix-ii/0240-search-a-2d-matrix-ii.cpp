class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++){
            
            bool check =  binary_search(matrix[i].begin(), matrix[i].end(), target);
            if(check) return true;
            
        }
        return false;
    }
};