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

    int power(int x , int n){
        int t = abs (n);

        if(t == 0) return 1;
        else if(t == 1) return x;

        long long ans = power(x, n/2);
            ans *= ans;

        if(t & 1) ans *= x;

        if(n >= 0) return ans;

        return 1/ans;
    }

    int countNodes(TreeNode* root) {
        
        if(!root) return 0;

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        if(leftHeight == rightHeight) return power(2,leftHeight) - 1;

        int countLeftNodes = countNodes(root->left);
        int countRightNodes = countNodes(root->right);

        return countLeftNodes + countRightNodes + 1;
    }

    int getLeftHeight(TreeNode* root){

        if(root == NULL) return 0;
        return (1 + getLeftHeight(root->left));
    }

    int getRightHeight(TreeNode* root){

        if(root == NULL) return 0;
        return (1 + getRightHeight(root->right));
    }

};