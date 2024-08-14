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
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }

    pair<bool, int> dfs(TreeNode*& root){
        if(!root){
            pair<bool, int> p = {true, 0};
            return p;
        }

        pair<bool, int> leftChild = dfs(root->left);
        pair<bool, int> rightChild = dfs(root->right);

        pair<bool, int> ans;
        // Calculating height
        ans.second = max(leftChild.second, rightChild.second) + 1;

        // Checking if the height balanced or not
        if(abs(leftChild.second - rightChild.second) > 1){
            ans.first = false;
            return ans;
        }

        ans.first = leftChild.first & rightChild.first;
        return ans;
    }

    /*bool dfs(TreeNode* & root){
        if(!root) return true;

        if(abs(height(root->left)- height(root->right)) > 1) return false;

        bool leftSide = dfs(root->left);
        bool rightSide = dfs(root->right);

        return leftSide & rightSide;
        
    }

    int height(TreeNode* & root){

        if(!root) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }*/
};