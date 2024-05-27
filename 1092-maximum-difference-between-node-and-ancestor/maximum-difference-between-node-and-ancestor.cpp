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
    int maxDiff = INT_MIN; 
    int maxAncestorDiff(TreeNode* root) {
        
        dfs(root);

        return maxDiff;

    }

    void dfs(TreeNode* root){

        if(root == NULL) return;

        if(root->left){
            TreeNode* child = root->left;
            diffFinder(root, child);
            dfs(root->left);
        }

        if(root->right){
            TreeNode* child = root->right;
            diffFinder(root, child);
            diffFinder(root, child);
            dfs(root->right);
        }

    }

    void diffFinder(TreeNode* root, TreeNode* child){
        if(child == NULL) return;

        int diff = abs(root->val - child->val);

        if(diff > maxDiff) maxDiff = diff;

        if(child->left) diffFinder(root, child->left);

        if(child->right) diffFinder(root, child->right);
    }

};