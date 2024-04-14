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
    int ans=0;
    void left_sum(TreeNode* root, bool flag){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL && flag==1){
            ans+=root->val;
            return ;
        }
        flag=1;
        left_sum(root->left,flag);
        flag=0;
        left_sum(root->right,flag);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        left_sum(root,0);
        return ans;
    }
};