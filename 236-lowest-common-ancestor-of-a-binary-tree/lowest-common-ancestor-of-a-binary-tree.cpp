/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return lca(root, p, q);
    }

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root == NULL) return NULL;

        if(root == p){
            return p;
        }

        else if(root == q){
            return q;
        }

        TreeNode* left_taraf_h_kya = lca(root->left, p, q);
        TreeNode* right_taraf_h_kya = lca(root->right, p, q);

        if(left_taraf_h_kya != NULL && right_taraf_h_kya != NULL) return root;
        else if(left_taraf_h_kya != NULL && right_taraf_h_kya == NULL) return left_taraf_h_kya;

        return right_taraf_h_kya;
    }
};