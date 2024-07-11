class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int source) {
        int m = times.size();

        // 1. creating graph
        unordered_map<int, vector<pair<int,int>>> adj;

        for(int i=0; i<m; i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }

        // 2. Dijkstra
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(n+1, 0);

        vector<int> ans(n+1, INT_MAX);

        ans[source] = 0;
        pq.push({0, source});
        visited[source] = true;

        while(!pq.empty()){
            pair<int, int> frontNode = pq.top();
            int dist = frontNode.first;
            int currNode = frontNode.second;

            pq.pop();
            visited[currNode] = true;
            // cout<<dist<<" ";

            for(auto &v : adj[currNode]){
                int node = v.first;
                int wt = v.second;
                // cout<<wt<<" "<<endl;

                if(wt + dist < ans[node]){
                    ans[node] = wt + dist;
                    pq.push({ans[node], node});
                    visited[node] = true;
                }

            }
        }

        int maxi = INT_MIN;
        for(int i=1; i <= n; i++){
            if(!visited[i]) return -1;
            // cout<<ans[i]<<" ";
            maxi = max(maxi, ans[i]);
        }

        return maxi;

    }
};