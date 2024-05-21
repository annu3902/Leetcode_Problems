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
    int maxDepth(TreeNode* root) {
        int levels = 0;
        if (root == NULL) return 0;

        // number of levels  == height of the tree from the root node

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();

            while(size--){
                TreeNode* front = q.front();
                q.pop();

                if(front -> left != NULL) q.push(front -> left);

                if(front -> right != NULL) q.push(front -> right);
            }

            levels++;
        }

        return levels;
    }
};