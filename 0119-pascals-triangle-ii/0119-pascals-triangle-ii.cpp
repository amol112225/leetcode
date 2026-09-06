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
};