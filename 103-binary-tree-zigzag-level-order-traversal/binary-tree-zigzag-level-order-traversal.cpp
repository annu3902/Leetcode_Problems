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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        bool leftToRight = true;

        queue<TreeNode*> q;
        q.push(root); 

        while(!q.empty()){

            int size = q.size();
            vector<int> ans(size, 0);

            for(int i=0; i<size; i++){
                int index = (leftToRight) ? i : size-i-1;
                TreeNode* frontNode = q.front();
                q.pop();

                ans[index] = frontNode->val;

                if(frontNode->left) {
                    q.push(frontNode->left);
                }

                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }

            leftToRight = 1-leftToRight;
            result.push_back(ans);

        }
        return result;
    }
};