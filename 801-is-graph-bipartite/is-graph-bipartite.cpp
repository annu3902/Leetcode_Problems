class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            if(color[i] == -1 && dfs(graph, color, i, 0) == false){
                return false;
            }
        }

        return true;
    }

    bool dfs(vector<vector<int>> &graph, vector<int> &color, int u, int currColor){

        color[u] = currColor;

        for(auto &v : graph[u]){
            if(color[v] == -1 && dfs(graph, color, v, 1-currColor) == false){
                return false;
            }
            else if(color[v] == color[u]) return false;
        }

        return true;
    }
};