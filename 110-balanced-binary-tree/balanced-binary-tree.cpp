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

        pair<bool, int> ans = dfs(root);
        return ans.first;

    }


    pair<bool, int> dfs(TreeNode* root){

        if(root == NULL){
            pair<bool, int> p = {true, 0};
            return p;
        }

        pair<bool, int> leftPair = dfs(root->left);
        pair<bool, int> rightPair = dfs(root->right);

        bool leftAns = leftPair.first;
        bool rightAns = rightPair.first;

        bool heightDiff = abs(leftPair.second - rightPair.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(leftPair.second, rightPair.second) + 1;
        
        if(leftAns && rightAns && heightDiff) ans.first = true;
        else{
            ans.first = false;
        }
        return ans;
    }

};