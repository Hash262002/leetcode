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
    void flatten(TreeNode* root) {
        TreeNode* temp=root;
        while(temp!=NULL){
            TreeNode* left=temp->left;
            TreeNode* right=temp->right;
            if(left!=NULL){
                temp->right=left;
                temp->left=NULL;
                while(left->right!=NULL){
                    left=left->right;
                }
                left->right=right;
                
            }
            temp=temp->right;
        }
    }
};