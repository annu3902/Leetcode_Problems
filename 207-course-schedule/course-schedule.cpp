class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        int edges = prerequisites.size();

        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0);
        for(int i=0; i<edges; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        // 1. inDegree Calculation
            inDegree[v]++;
        } 

        // Kahn's Algorithm
        queue<int> q;
        for(int u=0; u<n; u++){
            if(inDegree[u] == 0){
                q.push(u);
            }
        }

        // bfs
        int cnt=0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt++;
        
            for(auto &v : adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(cnt != n) return false;
        return true;

    }
};