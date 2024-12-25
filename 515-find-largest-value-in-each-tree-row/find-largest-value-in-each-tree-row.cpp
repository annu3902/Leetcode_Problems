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
template <typename T>
concept TreeNodeLike = requires(T node) {
    { node->val } -> std::totally_ordered;
    { node->left } -> std::convertible_to<T>;
    { node->right } -> std::convertible_to<T>;
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        return largestValuesHelper(root);
    }

private:


    template<TreeNodeLike T>
    auto largestValuesHelper(T root) -> vector<decltype(std::declval<T>()->val)> {
        if (not root) {
            return {};
        }
        using valType = decltype(TreeNode::val);
        vector<valType> res;
        deque<T> myDeque;
        myDeque.emplace_back(root);

        while (not myDeque.empty()) {
            const int n = myDeque.size();
            valType currMax = std::numeric_limits<valType>::min();
            for (int i{}; i < n; i++) {
                const auto currNode = myDeque.front();
                myDeque.pop_front();
                currMax = max(currMax, currNode->val);
                if (currNode->left) myDeque.emplace_back(currNode->left);
                if (currNode->right) myDeque.emplace_back(currNode->right);

            }
            res.emplace_back(currMax);
        }

        
        return res;
    }
};