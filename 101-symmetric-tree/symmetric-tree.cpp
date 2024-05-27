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
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) return true;

        return dfs(root->left, root->right);

    }

    bool dfs(TreeNode* child1, TreeNode* child2){

        if(!child1 && !child2) return true;

        if(!child1 && child2) return false;
        if(child1 && !child2) return false;


        if(child1->val != child2->val) return false;

        int leftAns = false;
        int rightAns = false;
        
        leftAns = dfs(child1->left, child2->right);
        rightAns = dfs(child1->right, child2->left);   

        return leftAns && rightAns;
    }
};