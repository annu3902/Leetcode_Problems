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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        dfs(root, 0, result);

        return result;
    }

    void dfs(TreeNode* &root, int level, vector<int>& result){

        if(!root) return ;

        if(result.size() == level){
            result.push_back(root->val);
        }

        if(root->right){
            dfs(root->right, level+1, result);
        }

        if(root->left){
            dfs(root->left, level+1, result);
        }

        return;
    }
};