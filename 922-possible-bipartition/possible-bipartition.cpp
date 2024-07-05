class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        vector<int> color(n+1, -1);

        unordered_map<int, vector<int>> adj;
        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }


        for(int i=1; i<=n; i++){
            if(color[i] == -1 && bfs(adj, color, i) == false){
                return false;
            }
        }

        return true;
    }

    bool bfs(unordered_map<int,vector<int>> &adj, vector<int> &color, int u){

        queue<pair<int, int>> q;
        q.push({u, 0});

        while(!q.empty()){
            pair<int, int> frontNode = q.front();
            int u = frontNode.first;
            int clr = frontNode.second;
            q.pop();

            for(auto &v : adj[u]){
                if(color[v] == -1){
                    color[v] = 1-clr;
                    q.push({v, color[v]});
                }

                else if(color[v] == clr) return false;
            }
        }

        return true;

    }
};