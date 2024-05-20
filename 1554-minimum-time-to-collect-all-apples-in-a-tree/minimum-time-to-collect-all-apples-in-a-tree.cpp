class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)  {
        
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<edges.size(); i++){

            // edges[0] = {0,1}
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = dfs(0, -1, adj, hasApple);
        ans = (ans == 0) ? 0 : ans-2;
        return ans;
    }


    int dfs(int node, int parent, unordered_map<int, vector<int>>& adj, vector<bool> &hasApple){
        int paise = 0;

        for(auto& v: adj[node]){

            if(v == parent) continue;

            paise += dfs(v, node, adj, hasApple);

        }
        
        if(paise != 0 || hasApple[node] == true) paise += 2;

        return paise;
    }

};