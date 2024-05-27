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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
           
        string temp;
        dfs(root1, temp);
        string comp = temp;
        temp.clear();
        dfs(root2, temp);

        if(comp == temp) return true;
        return false;
    }

    void dfs(TreeNode* root, string &temp){

        if(!root->left && !root->right){
            temp.push_back(root->val + '0');
            return;
        }

        if(root->left) dfs(root->left, temp);
        if(root->right) dfs(root->right, temp);

    }
};