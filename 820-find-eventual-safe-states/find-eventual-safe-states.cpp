class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDegree(n, 0);
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<n; i++){
            inDegree[i] += graph[i].size();
            for(int j=0; j<graph[i].size(); j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        queue<int> q;
        vector<int> visited(n, 0);

        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto&v: adj[node]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(visited[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};