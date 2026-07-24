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
    bool check(TreeNode* root, int targetSum, int &pathSum){
        if(root==NULL) return false;
        pathSum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(targetSum==pathSum) return true;
        }
        if(root->left) if(check(root->left, targetSum, pathSum)==true) return true;
        if(root->right) if(check(root->right, targetSum, pathSum)==true) return true;
        pathSum-=root->val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int pathSum = 0;
        return check(root,targetSum,pathSum);
    }
};