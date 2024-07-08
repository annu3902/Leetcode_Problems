class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges < n-1) return -1;

        unordered_map<int,vector<int>> adj;
        for(vector<int> & connection : connections){
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, 0);
        int cnt=0;

        for(int u=0; u<n; u++){
            if(!visited[u]){
                dfs(adj, visited, u, -1);
                cnt++;
            }
        }
        return cnt-1;
    }

    void dfs(unordered_map<int,vector<int>> &adj, vector<bool> &visited, int u, int parent){
        visited[u] = true;

        for(auto &v :adj[u]){
            if(v == parent) continue;
            else if(visited[v]) continue;
            else if(!visited[v]){
                dfs(adj, visited, v, u);
            }
        }
    }
};