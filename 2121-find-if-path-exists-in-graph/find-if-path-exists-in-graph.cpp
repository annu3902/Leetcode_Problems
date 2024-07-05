class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int frontNode = q.front();
            if(frontNode == destination) return true;
            q.pop();

            for(auto &v : adj[frontNode]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }

        }

        return false;

    }
};