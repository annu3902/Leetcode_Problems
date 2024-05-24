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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return{};
        // if(root -> left == NULL && root -> right == NULL && root -> val == targetSum) return{{targetSum}};

        vector<vector<int>> result;
        vector<int> ans;
        int sum = 0;

        dfs(root, targetSum, sum, ans, result);

        return result;
    }

    void dfs(TreeNode* root, int& targetSum, int sum, vector<int> ans, vector<vector<int>> &result){
        if(root == NULL) return;

        sum += root->val; // taking the value of node in account
        ans.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                result.push_back(ans);
            }
            return;
        }

        dfs(root->left, targetSum, sum, ans, result);
        dfs(root->right, targetSum, sum, ans, result);
        
    }

    bool isLeafNode(TreeNode* root){
        if(root == NULL) return true;
        if(root -> left == NULL && root -> right) return true;
        return false;
    }
};