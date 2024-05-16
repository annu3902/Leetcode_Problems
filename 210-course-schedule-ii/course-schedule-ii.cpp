class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        int m=prerequisites.size();
        vector<int> inDegree(n, 0);
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<m; i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
            // inDegree Calculation
            inDegree[a]++;
        }

        // Kahn's algo
        queue<int> q;
        for(int u=0; u<n; u++){
            if(inDegree[u] == 0){
                q.push(u);
            }
        }
        
        vector<int> result;
        vector<bool> visited(n, false);
        int cnt=0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);
            visited[u] = true;
            cnt++;

            for(auto &v : adj[u]){
                inDegree[v]--;
                if(!inDegree[v]) q.push(v);
            }
        }


        if(cnt != n) return{};
        return result;
    }

};