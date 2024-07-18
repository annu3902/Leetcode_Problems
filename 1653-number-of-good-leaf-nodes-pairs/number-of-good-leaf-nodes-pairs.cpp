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
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj; // Forming a Graph from a Tree
        unordered_set<TreeNode*> st; // Storing all the leaf nodes

        makeGraph(root, NULL, adj, st);

        int count = 0;

        for(auto &leafNode : st){
            
            // Simple BFS run
            unordered_set<TreeNode*> visited; // Visited vector for TreeNode
            queue<TreeNode*> q;
            q.push(leafNode);
            visited.insert(leafNode);                

            for(int level=0; level <= distance; level++){
                int size = q.size();

                while(size--){
                    TreeNode* frontNode = q.front();
                    q.pop();

                    if(frontNode != leafNode && st.count(frontNode)){
                        count++;
                    }

                    for(auto & v : adj[frontNode]){
                        if(!visited.count(v)){
                            q.push(v);
                            visited.insert(v);
                        }
                    }
                }
            }

        }

        return (count/2);

    }

    void makeGraph(TreeNode* root, TreeNode* prevNode, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& st){
        if(!root) return;
        if(root->left == NULL && root->right == NULL) st.insert(root);
        if(prevNode) {
            adj[root].push_back(prevNode);
            adj[prevNode].push_back(root);
        }
        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);
        return;
    }
};