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
        
        int maxSum = INT_MIN;

        solve(root, maxSum);

        return maxSum;
    }

    int solve(TreeNode* root, int& maxSum){
        if(root == NULL) return 0;

        int left_bacche_ka_Sum = solve(root->left, maxSum);
        int right_bacche_ka_Sum = solve(root->right, maxSum);

        int niche_answer_mil_gya = left_bacche_ka_Sum + right_bacche_ka_Sum + root->val;

        int koii_ek_acha_hai = max(left_bacche_ka_Sum, right_bacche_ka_Sum) + root->val;

        int sirf_root_acha_hai = root->val;

        maxSum = max({maxSum, niche_answer_mil_gya, koii_ek_acha_hai, sirf_root_acha_hai});

        return max(koii_ek_acha_hai, sirf_root_acha_hai);

    }

};