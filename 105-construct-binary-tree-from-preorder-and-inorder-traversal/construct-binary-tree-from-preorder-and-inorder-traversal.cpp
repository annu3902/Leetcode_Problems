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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idxRoot = 0;

        return solve(preorder, inorder, 0, n-1, idxRoot);

    }

    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int start, int end, int &idxRoot){

        if(start > end) return NULL; // base case

        int rootValue = preorder[idxRoot];

        int i = start;
        for(i = start; i <= end; i++){
            if(inorder[i] == rootValue){
                break; // found the i
            }
        }

        TreeNode* root = new TreeNode(preorder[idxRoot]);
        idxRoot++;

        root -> left = solve(preorder, inorder, start, i-1, idxRoot);
        root -> right = solve(preorder, inorder, i+1, end, idxRoot);
        return root;
    }

};