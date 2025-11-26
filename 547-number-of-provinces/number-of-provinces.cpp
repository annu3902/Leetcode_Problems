class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int u, vector<bool>& visited){
        visited[u] = true;

        for(int v=0; v<isConnected.size(); v++){
            if(!visited[v] && isConnected[u][v]){
                dfs(isConnected, v, visited);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 

        // Number of dfs counts will be my ans
        vector<bool> visited(n, 0);
        int count=0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(isConnected, i, visited);
                count++;
            }
        }

        return count;
    }
};