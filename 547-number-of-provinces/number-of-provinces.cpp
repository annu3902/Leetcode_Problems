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

        queue<int> q;
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        else if(!visited[i]){
            q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            visited[0] = true;
            q.pop();
            for(int v=0; v<n; v++){
                if(!visited[v] && isConnected[u][v] == 1){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        count++;
    }
        

        return count;
    }
};