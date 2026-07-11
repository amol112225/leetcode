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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;
        int r=preorder[0];
        vector<int>inl;
        vector<int>inr;
        int i=0;
        int count=0;
        while(inorder[i]!=r){
            inl.push_back(inorder[i]);
            i++;
            count++;
        }
        i++;
        while(i<inorder.size()){
            inr.push_back(inorder[i]);
            i++;
        }
        vector<int>prel;
        vector<int>prer;
        for(int j=1; j<=count;j++){
            prel.push_back(preorder[j]);
        }
        for(int j=count+1; j<preorder.size(); j++){
            prer.push_back(preorder[j]);
        }
        TreeNode* root = new TreeNode(r);
        root->left = buildTree(prel,inl);
        root->right = buildTree(prer,inr);
        return root;
    }
};