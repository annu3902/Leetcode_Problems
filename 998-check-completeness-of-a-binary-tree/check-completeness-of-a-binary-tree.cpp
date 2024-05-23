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
    bool isCompleteTree(TreeNode* root) {
        if(root -> left == NULL && root -> right == NULL)return true;

        //1. Finding the total node cnt;
        // calling the preorder traversal;
        // Number of calls gives the total node cnt

        int totalNodes = preorder(root);

        //2. nodes m index value assign krte h
        return check(root, totalNodes, 1);
    }

    int preorder(TreeNode* root){
        if(root == NULL) return 0;

        int cnt = 1;
        cnt += preorder(root->left);
        cnt += preorder(root->right);

        return cnt;
    }
    
    bool check(TreeNode* root, int totalNodes, int currIndex){
        if(root == NULL) return true;

        if(currIndex > totalNodes) return false;

        bool left_part = check(root -> left, totalNodes, 2*currIndex);
        bool right_part = check(root -> right, totalNodes, 2*currIndex + 1);

        return left_part & right_part;
    }

};