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
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return root->val;

        queue<TreeNode*> q;
        q.push(root);   
        int bottomMostValue = root->val;

        while(!q.empty()){
            int size = q.size();
            bottomMostValue = q.front()->val;

            while(size--){

                TreeNode* front = q.front();
                q.pop();

                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);

            }
        }

        return bottomMostValue;
    }
};