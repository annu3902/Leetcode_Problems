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
    int maxPathSum(TreeNode* root) {
        int maxSum = -1e9;
        maxSum = max(maxSum, dfs(root, maxSum));
        return maxSum;
    }

    int dfs(TreeNode* &root, int& maxSum){
        if(!root) return -1e9;

        if(root->left == NULL && root->right == NULL){
            return root->val;
        }

        int leftSum = dfs(root->left, maxSum);
        int rightSum = dfs(root->right, maxSum);

        int nicheAnsMilRha = leftSum + rightSum + root->val;

        maxSum = max({maxSum, nicheAnsMilRha, leftSum, rightSum, root->val});

        return max(max(leftSum, rightSum) + root->val , root->val);
    }
};