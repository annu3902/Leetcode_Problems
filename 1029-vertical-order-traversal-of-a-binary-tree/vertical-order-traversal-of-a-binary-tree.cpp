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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;

        map < int, map <int, vector<int>> > mp;
        queue < pair <TreeNode*, pair<int, int> > > q;
        q.push({root, {0, 0}});

        while(!q.empty()){

            int size = q.size();
            while(size--){

                pair<TreeNode*, pair<int, int>> temp = q.front();
                q.pop();

                TreeNode* frontNode = temp.first;
                pair<int, int> p = temp.second;
                int hd = p.first;
                int currLevel = p.second;

                mp[hd][currLevel].push_back(frontNode->val);

                if(frontNode->left){
                    q.push({frontNode->left, {hd-1, currLevel+1}});
                }

                if(frontNode -> right){
                    q.push({frontNode->right, {hd+1, currLevel + 1}});
                }

            }

        }

        for(auto &it : mp){
            vector<int> ans;
            for(auto &level : it.second){
                vector<int> temp = level.second;
                sort(begin(temp), end(temp));
                for(auto j : temp){
                    ans.push_back(j);
                }
            }   
            result.push_back(ans);         
        }

        return result;
    }
};