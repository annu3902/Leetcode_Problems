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

    int inOrderTraversal(TreeNode* root){
        if(root == NULL) return 0;

        int cnt = 1;
        int left_ka_baccha = inOrderTraversal(root->left);
        int right_ka_baccha = inOrderTraversal(root->right);

        return (cnt + max(left_ka_baccha, right_ka_baccha));

    }

    int maxDepth(TreeNode* root) {
        // depth of recursion jitni hogi utne hi levels ya height hoga
        return inOrderTraversal(root);
    }
};