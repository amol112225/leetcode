/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void rview(TreeNode* node, int level,vector<int>&res){
        if(node==NULL) return;
        if(level==res.size()) res.push_back(node->val);
        rview(node->right,level+1,res); 
        rview(node->left,level+1,res); 
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        int level = 0;
        rview(root,level,result);
        return result;
    }
};