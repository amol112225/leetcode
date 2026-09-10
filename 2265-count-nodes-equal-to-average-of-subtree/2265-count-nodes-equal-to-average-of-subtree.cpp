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
    void helper(TreeNode* root, int & sum, int & n){
        if(root==NULL) return;
        helper(root->left, sum,n);
        sum+=root->val;
        n++;
        helper(root->right,sum,n);
    }
    int avg(TreeNode* root){
        int sum = 0;
        int n = 0;

        helper(root,sum,n);
        return sum/n;
    }
    void ans(TreeNode* root, int &cnt){
        if(root==NULL) return;
        ans(root->left,cnt);
        if(root->val==avg(root)) cnt++;
        ans(root->right,cnt);
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        int cnt = 0;
        ans(root,cnt);
        return cnt;



    }
};