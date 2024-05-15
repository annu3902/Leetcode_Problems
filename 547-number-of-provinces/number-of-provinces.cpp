class Solution {
public:
    void dfs (unordered_map<int, vector<int>> &adj, vector<bool> &visited, int node){

        visited[node] = true;

        for(auto &v : adj[node]){
            if(!visited[v]){
                dfs(adj, visited, v);
            }
        }
        return;
    }
    

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int cnt=0;
        vector<bool> visited(n, false);

        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                else if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adj, visited, i);
                cnt++;
            }
        }

        return cnt;
    }
};