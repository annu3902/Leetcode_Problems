class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, bool currColor){
        color[node] = currColor;

        for(auto & v: graph[node]){
            if(color[v] == -1 && dfs(v, graph, color, 1-currColor) == false) return false;
            else if(color[v] == currColor) return false;
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);

        for(int i=0; i<n; i++){
            if(color[i] == -1 && dfs(i, graph, color, 0) == false){
                return false;
            }
        }

        return true;
    }
};