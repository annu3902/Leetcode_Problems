class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& inRecurssion){
        if(visited[node] == 0){
            return false;
        }
        
        visited[node] = 1;
        inRecurssion[node] = 1;

        for(auto &v : graph[node]){
            if(inRecurssion[v] == -1 && dfs(v, graph, visited, inRecurssion) == true){
               return true;
            }
            else if(inRecurssion[v] == 1){
                return true;
            } 
        }

        inRecurssion[node] = -1;
        visited[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        vector<int> inRecurssion(n, -1);
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(visited[i] == -1){
                dfs(i, graph, visited, inRecurssion);
            }
            
        }

        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};