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
    void check(TreeNode* root, int targetSum,vector<int>&currAns, vector<vector<int>>&ans,int &pathSum){
        if(root==NULL) return;
        pathSum+=root->val;
        currAns.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(pathSum==targetSum) ans.push_back(currAns);
        }
        if(root->left){
            check(root->left,targetSum,currAns,ans,pathSum);
        }
        if(root->right) check(root->right, targetSum, currAns, ans, pathSum);
        if(currAns.size()>0) currAns.pop_back();
        pathSum-=root->val;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int pathSum = 0;
        vector<int>currAns;
        vector<vector<int>>ans;
        check(root,targetSum, currAns,ans,pathSum);
        return ans;
    }
};