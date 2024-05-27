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
    long long maxProdct = 0;
    int mod = 1e9+7;
    long long maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, int> mpp;
        int sum = getSum(root, mpp);

        dfs(root, mpp, sum);
        return maxProdct % mod;
        
    }

    void dfs(TreeNode* root, unordered_map<TreeNode*, int> &mpp, int &sum){

        if(root == NULL) return;
        
        solve(root->left, mpp, sum);
        solve(root->right, mpp, sum);

        dfs(root->left, mpp, sum);
        dfs(root->right, mpp, sum);
    }

    void solve(TreeNode* child, unordered_map<TreeNode*, int> & mpp, int &sum){
        if(!child) return;

        long long childSum = mpp[child];
        long long  parentSum = sum - childSum;

        maxProdct = max(static_cast<long long>(childSum*parentSum), maxProdct);
    }


    int getSum(TreeNode* root, unordered_map<TreeNode*,int> & mpp){
        
        if(root == NULL) return 0;

        int leftSum = getSum(root->left, mpp);
        int rightSum = getSum(root->right, mpp);

        mpp[root] = leftSum + rightSum + root->val;
 
        return mpp[root];
    }
};