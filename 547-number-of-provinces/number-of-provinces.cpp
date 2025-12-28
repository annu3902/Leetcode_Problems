class Solution {
public:
    void dfs(int node, vector<bool>& visited, unordered_map<int, vector<int>>& adj){
        visited[node] = true;

        for(auto& v:adj[node]){
            if(!visited[v]){
                dfs(v, visited, adj);
            }
        }

        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);

        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                else if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited, adj);
                cnt++;
            }
        }

        return cnt;
    }
};