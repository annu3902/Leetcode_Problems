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

    int diameterOfBinaryTree(TreeNode* root) {
    if(root->left == NULL && root->right == NULL) return 0;
        int maxLength = 0;
        solve(root, maxLength);
        return maxLength - 1;
    }

    int solve(TreeNode* root, int &maxLength){

        if(root == nullptr) return 0;

        int left_bacche_ka_length = solve(root->left, maxLength);

        int right_bacche_ka_length = solve(root->right, maxLength);

        int niche_ans_mil_gya = left_bacche_ka_length + right_bacche_ka_length + 1;

        maxLength = max({maxLength, left_bacche_ka_length, right_bacche_ka_length, niche_ans_mil_gya});

        return max(left_bacche_ka_length, right_bacche_ka_length) + 1; 

    } 
};