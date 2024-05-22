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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int indexNode = n-1;

        return solve(inorder, postorder, 0, n-1, indexNode);
    }

    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int start, int end, int &indexNode){

        if(start > end) return NULL;

        int rootNode = postorder[indexNode];
        if(indexNode > 0)
            indexNode--;

        int i = start;

        for(i = start; i <= end; i++){
            if(inorder[i] == rootNode){
                break;
            }
        }

        TreeNode* root = new TreeNode(rootNode);
        root -> right = solve(inorder, postorder, i + 1, end, indexNode);
        root -> left = solve(inorder, postorder, start, i - 1, indexNode);

        return root;
    }
};