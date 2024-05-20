class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        // Graph bna lete h
        unordered_map<int, vector<int>> adj;

        for(vector<int> edge : edges){
            // edge = {0,1}
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> count(26,0);
        vector<int> result(n, 0);
        dfs(0, -1, adj, labels, count, result);

        return result;
    }


    void dfs(int currNode, int parentNode, unordered_map<int, vector<int>> &adj, string &labels, vector<int> &count, vector<int> &result){

        char currLabel = labels[currNode];

        int baccho_s_milne_k_phle = count[currLabel - 'a'];

        count[currLabel - 'a'] += 1;

        for(auto& v: adj[currNode]){

            if(v == parentNode) continue;

            dfs(v, currNode, adj, labels, count, result);

        }

        int baccho_s_milne_k_bad = count[currLabel - 'a'];

        result[currNode] = baccho_s_milne_k_bad - baccho_s_milne_k_phle;
    }
};