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

    bool symetric(TreeNode* left,TreeNode* right)
    {
        if(left==NULL || right ==NULL)
        {
            return left==right;
        }
        if(left->val != right->val)
        {
            return false;
        }
        return symetric(left->left, right->right) && symetric(left->right , right->left);
    }
    
    
    public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        return symetric(root->left,root->right);
    }
};