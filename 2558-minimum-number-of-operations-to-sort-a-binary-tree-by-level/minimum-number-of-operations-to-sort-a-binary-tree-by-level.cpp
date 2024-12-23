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

#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
  /*struct TreeNode {*/
  /*    int val;*/
  /*    TreeNode *left;*/
  /*    TreeNode *right;*/
  /*    TreeNode() : val(0), left(nullptr), right(nullptr) {}*/
  /*    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}*/
  /*    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}*/
  /*};*/

class UF {
private:
    int count;
    vector<int> parent;
    vector<int> size;

public:
    UF(int n) {
        this->count = n;
        parent = vector<int>(n, 0);
        size = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    virtual ~UF() {}

    void Union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;

        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int getCount() {
        return count;
    }

    // New Method: Get component sizes
    vector<int> getComponentSizes() {
        unordered_map<int, int> componentSize;
        for (int i = 0; i < parent.size(); i++) {
            int root = find(i);
            componentSize[root]++;
        }
        vector<int> sizes;
        for (auto& entry : componentSize) {
            sizes.push_back(entry.second);
        }
        return sizes;
    }

private:
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        
        using element = pair<TreeNode*, int>;
        vector<int> nums;
        queue<element> Q;
        int result = 0;
        int current_level = 0;
        Q.push(make_pair(root, 0));

        while (Q.size()){
            // Getting the node
            auto [node, level] = Q.front(); Q.pop();

            // check if we discoverd a a new node
            if (level != current_level){
                // we need to perform the computation for the number of nodes that are not in place
                result += num_swap(nums);
                nums.clear();
                current_level = level;
            }
            nums.push_back(node->val);

            if (node->left){
                Q.push(make_pair(node->left, level+1));
            }

            if (node->right){
                Q.push(make_pair(node->right, level+1));
            }

        }
        // .final level
        result += num_swap(nums);
        
        return result;
    }
    int num_swap(vector<int> & nums){
        using element = pair<int,int>;
        vector<element> sorted;
        int n = nums.size();
        for (int i=0; i < n; i++){
            sorted.push_back(make_pair(nums[i], i));
        }
        sort(sorted.begin(), sorted.end());

        // making the conexion
        auto uf = UF(n);
        for(int i=0; i < n; i++){
            if (nums[i] != sorted[i].first){
                uf.Union(i, sorted[i].second);
            }
        }
        // counting the number of swaps
        auto count = 0;
        for(auto v : uf.getComponentSizes()){
            count += v-1;
        }
        return count;

    }
};