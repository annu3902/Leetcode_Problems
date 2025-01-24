class Solution {
public:
    vector<bool> notCycled;
    bool dfs(vector<int> &color, int u, vector<vector<int>> &adj){
        color[u] = 1;
        for(auto v: adj[u]){
            if(color[v] == -1 && dfs(color, v, adj) == true) return true;
            else if(color[v] == 1) return true;
        }
        color[u] = 0;
        notCycled[u] = true;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        notCycled.assign(n, false);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                dfs(color, i, graph);
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(notCycled[i]) ans.push_back(i);
        }
        return ans;
    }
};