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
    int findBottomLeftValue(TreeNode* root) {
        
        if(root == NULL) return 0;

        if(root->left == NULL && root->right == NULL) return root->val;

        int maxDepth = -1; 
        int result = -1;
        solve(root, 0, maxDepth, result);

        return result;
    }

    void solve(TreeNode* &root, int depth, int &maxDepth, int &result){
        if(root == NULL) return;

        if(maxDepth < depth){
            maxDepth = depth;
            result = root->val;
        }

        solve(root->left, depth+1, maxDepth, result);
        solve(root->right, depth+1, maxDepth, result);
    }
};