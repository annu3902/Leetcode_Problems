class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& edges) {

        // Graph formation
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<edges.size(); i++){
                // edges[0] = {1,2}
                // 1 -> 2;
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color (n+1,-1);
        for(auto & it : adj){
            cout<<it.first<<" -> "; 
            for(int &x: it.second){
                cout<<x<<" ";
            } 
            cout<<endl;      
        }

        for(int i=1; i<=n; i++){

            if(color[i] == -1 && dfs(i, adj, color, 0) == false){
                return false;                
            }
        }

        return true;
    }


    bool dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &color, int currColor){

            color[node] = currColor;

            currColor = 1- currColor;

            for(auto &v : adj[node]){
                if(color[v] == color[node]) return false;

                else if(color[v] == -1 && dfs(v, adj, color, currColor) == false){
                    return false;
                }

            }
        return true;
    }
};