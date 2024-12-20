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
vector<int> nums;
int i=0;
class Solution {
public:
    void Preorder_Traversal_left(TreeNode* root, int level){
        if(root == nullptr)
            return;

        if(level%2==1)
            nums.push_back(root-> val);
        

        Preorder_Traversal_left(root->left, level+1);
        Preorder_Traversal_left(root->right, level+1);
    }

    void Preorder_Traversal_right(TreeNode* root, int level){
        if(root == nullptr)
            return;

        if(level%2==1){
            root->val=nums[i];
            i++;
        }

        Preorder_Traversal_right(root->right, level+1);
        Preorder_Traversal_right(root->left, level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {       
        Preorder_Traversal_left(root, 0);
        Preorder_Traversal_right(root, 0);
        return root;
    }
};