class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        // 1. graph formation
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<edges.size(); i++){
            // i=0;
            // edges[0] = {0,1}
            // 0 - 1
            // 1 - 0
            vector<int> vec = edges[i];
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){

            int u = q.front();
            q.pop();
            if(u == destination) return true;

            for(auto &v : adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }
};