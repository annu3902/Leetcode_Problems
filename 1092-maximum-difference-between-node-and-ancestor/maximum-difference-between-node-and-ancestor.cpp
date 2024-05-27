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
    int maxAncestorDiff(TreeNode* root) {
        // Efficient Solution
        pair<int, int> p = {root->val, root->val};

        return dfs(root, p);
    }


    int dfs(TreeNode* root, pair<int, int> p){

        if(!root){
            int maxiVal = p.first; 
            int miniVal = p.second; 
            cout<<maxiVal<<" "<<miniVal<<endl;
            return {maxiVal - miniVal};
        }

        p.first = max(p.first, root->val);
        p.second = min(p.second, root->val);

        int leftAns = dfs(root->left, p);
        int rightAns = dfs(root->right, p);

        return max(leftAns, rightAns);
    }

};