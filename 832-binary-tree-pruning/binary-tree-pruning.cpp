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
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root == NULL) return NULL;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if(isOnePresent(root)) return root;

        return NULL;
    }

    bool isOnePresent(TreeNode* root){

        if(root == NULL) return false;

        if(root -> val == 1) return true;

        return (isOnePresent(root->left) || isOnePresent(root->right));

    }
};