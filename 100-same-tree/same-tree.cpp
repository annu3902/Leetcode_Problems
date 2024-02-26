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
//
// Algorithm for the recursion:
// 1)
// If one of the node is NULL then return the equality result of p an q.
// This boils down to if both are NULL then return true, 
// but if one of them is NULL but not the other one then return false
// 2)
// At this point both root nodes represent valid pointers.
// Return true if the root nodes have same value and 
// the left tree of the roots are same (recursion)
// and the right tree of the roots are same (recursion). 
// Otherwise return false. 
//

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});
        while (!st.empty()) {
            auto [node1, node2] = st.top();
            st.pop();
            if (!node1 && !node2) continue;
            if (!node1 || !node2 || node1->val != node2->val) return false;
            st.push({node1->left, node2->left});
            st.push({node1->right, node2->right});
        }
        return true;
    }
};