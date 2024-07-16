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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        map<TreeNode*, TreeNode*> par;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        TreeNode* src = nullptr;
        TreeNode* dst = nullptr;
        
        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            TreeNode* pr = q.front().second;
            par[curr] = pr;
            if (curr->val == startValue) src = curr;
            if (curr->val == destValue) dst = curr;
            q.pop();
            if (curr->left) q.push({curr->left, curr});
            if (curr->right) q.push({curr->right, curr});
        }

        queue<pair<TreeNode*, char>> q1;
        q1.push({src, '0'});

        map<int, char> move;
        int path[100005];
        memset(path, -1, sizeof(path));
        
        while (!q1.empty()) {
            TreeNode* curr = q1.front().first;
            char how = q1.front().second;
            move[curr->val] = how;
            if (curr == dst) break;
            q1.pop();

            if (curr->left && move.find(curr->left->val) == move.end()) {
                q1.push({curr->left, 'L'});
                path[curr->left->val] = curr->val;
            }
            if (curr->right && move.find(curr->right->val) == move.end()) {
                q1.push({curr->right, 'R'});
                path[curr->right->val] = curr->val;
            }
            if (par[curr] && move.find(par[curr]->val) == move.end()) {
                q1.push({par[curr], 'U'});
                path[par[curr]->val] = curr->val;
            }
        }

        string res;
        int i = destValue;

        while (i != -1) {
            if (move[i] != '0') res.push_back(move[i]);
            i = path[i];
        }

        reverse(res.begin(), res.end());

        return res;
    }
};