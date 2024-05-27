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
    int findSecondMinimumValue(TreeNode* root) {
        
        if(root->left == NULL && root->right== NULL) return -1;

        int mini = root->val;
        long long secMin = LONG_MAX;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                TreeNode* node = q.front();
                q.pop();

                if(node->val > mini && node->val < secMin){
                    secMin = node->val;
                    // flag = true;
                }

                // else{
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                // }

            }
        }

        secMin = (secMin == LONG_MAX) ? -1 : secMin;
        return secMin;

    }
};