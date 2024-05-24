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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;

        dfs(root, st, result);
        if(st.find(root->val) == st.end()){
            result.push_back(root);
        }

        return result;  
    }
    
    TreeNode* dfs(TreeNode* &root, unordered_set<int> &st, vector<TreeNode*> &result){

        if(root == NULL) return NULL;

        root->left = dfs(root->left, st, result);
        root->right = dfs(root->right, st, result);

        if(st.count(root->val)){
            if(root->left != NULL) result.push_back(root->left);
            if(root->right != NULL) result.push_back(root->right);

            return NULL;
        }
        return root;
    }

};