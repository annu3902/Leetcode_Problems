/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool checkPath(TreeNode* curr, ListNode* lst) {
        if (lst == nullptr) return true;
        if (curr == nullptr || curr->val != lst->val) return false;
        return checkPath(curr->left, lst->next) || checkPath(curr->right, lst->next);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) continue;

            if (curr->val == head->val) {
                bool isPathAval = checkPath(curr, head);
                if (isPathAval) return true;
            }

            q.push(curr->left);
            q.push(curr->right);
        }

        return false;
    }
};