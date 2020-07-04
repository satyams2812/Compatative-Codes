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
    
    void RightView(TreeNode* root,int level,int &maxLevel,vector<int>&res)
    {
        if(root==NULL)
        {
            return;
        }
        if(level>maxLevel)
        {
            res.push_back(root->val);
            maxLevel = level;
        }
        RightView(root->right, level+1, maxLevel,res);
            RightView(root->left, level+1, maxLevel,res);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int maxLevel = -1;
        RightView(root,0,maxLevel,res);
        return res;
    }
};
