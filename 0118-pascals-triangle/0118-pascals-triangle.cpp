class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long el = 1;
        vector<int>ans;
        ans.push_back(1);
        int row = rowIndex+1;
        for(int col = 1; col<row; col++){
            el = el*(row-col);
            el = el/col;
            ans.push_back((int)el);
        }
        return ans;

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0; i<numRows; i++){
            ans.push_back(getRow(i));
        }
        return ans;
    }
};