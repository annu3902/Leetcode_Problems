class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){
        visited[u] = true;

        for(auto &v: adj[u]){
            if(!visited[v]){
                dfs(adj, v, visited);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                else if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        // Number of dfs counts will be my ans
        vector<bool> visited(n, 0);
        int count=0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adj, i, visited);
                count++;
            }
        }

        return count;
    }
};