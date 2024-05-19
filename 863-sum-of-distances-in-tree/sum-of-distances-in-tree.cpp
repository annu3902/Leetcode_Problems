class Solution {
public:
    int N;
    vector<int> children;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        N=n;

        // Graph formation
        unordered_map<int, vector<int>> adj;
        for(vector<int> edge : edges){
            int u =edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        unordered_map<int,int> parent;
        queue<int> q;

        q.push(0);
        visited[0] = true;
        parent[0] = -1;
        int sum=0;

        int level = 0;

        // Level order traversal
        while(!q.empty()){  
            int size = q.size();
            while(size--){
                int u = q.front();
                sum += level;
                q.pop();

                for(auto &v : adj[u]){
                    if(!visited[v]){
                        q.push(v);
                        visited[v] = true;
                        parent[v] = u;
                    }
                }
            }
            level++;
        }

        vector<int> result(n, -1);
        result[0] = sum;

        children.resize(n,0);
        children[0] = dfsChild(0, -1, adj);

        queue<pair<int, int>> que;
        fill(visited.begin(), visited.end(), false);

        que.push(make_pair(0, -1));

        while(!que.empty()){
            int size = que.size();

            while(size--){

                int child = que.front().first;
                int parent = que.front().second;
                int ch = children[child];
                que.pop();

                for(auto &v : adj[child]){

                    if(!visited[v]){
                        que.push({v, child});
                        visited[v] = true;
                    }

                }

                if(parent != -1 && result[child] == -1){
                    cout<<child<<" "<<parent<<" "<<result[parent]<<endl;
                    result[child] = result[parent] - ch + (n - ch);
                }
                
            }
        }

        return result;

    }

    int dfsChild(int node, int parent, unordered_map<int, vector<int>> &adj){
        children[node] = 1;
        int totalNode = 1;

        for(auto &v : adj[node]){
            if(v == parent) continue;

            totalNode += dfsChild(v, node, adj);
        }
        return children[node] = totalNode;
    }
};