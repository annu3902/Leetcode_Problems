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
    vector<long long> levelSum;

    // BFS to find all the level sum
    void findLevelSum(TreeNode* root){
        queue<TreeNode*> curr, next;
        curr.push(root);
        int currLevel = 0;

        while(!curr.empty()){
            auto tp = curr.front();
            curr.pop();
            if(levelSum.size() == currLevel){
                levelSum.push_back(tp->val);
            }
            else{
                levelSum[currLevel] += tp->val;
            }

            if(tp->left) next.push(tp->left);
            if(tp->right) next.push(tp->right);

            if(curr.empty()){
                curr = next;
                next = queue<TreeNode*>();
                currLevel++;
            }

        }
    }

    // DFS to update the values
    void dfs(TreeNode *root, long long siblingSum, int level){
        root-> val = levelSum[level] - siblingSum;
        long long childSum = 0;
        if(root->left)  childSum += root->left->val;
        if(root->right)  childSum += root->right->val;

        if(root->left)
            dfs(root->left, childSum, level+1);
        if(root->right)
            dfs(root->right, childSum, level+1);
    }

    
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root)   return root;
        findLevelSum(root);
        
        dfs(root, levelSum[0], 0);
        
        return root;
    }
};