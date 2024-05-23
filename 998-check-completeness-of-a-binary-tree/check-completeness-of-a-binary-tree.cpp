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
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                TreeNode* front = q.front();
                q.pop();

                if(front -> left != NULL){
                    if(flag == false)
                        q.push(front->left);
                    else{
                        return false;
                    }
                }
                else{
                    flag = true;
                }
                if(front -> right != NULL){
                    if(flag == false)
                        q.push(front->right);
                    else{
                        return false;
                    }
                }
                else{
                    flag = true;
                }

            }

        }

        return true;

    }
};