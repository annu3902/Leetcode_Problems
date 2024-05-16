class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        int m =prerequisites.size();
        unordered_map<int, vector<int>> adj;

        // {a,b} = b -> a
        for(int i=0; i<m; i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
        }

        // 2. toposort check
        vector<int> result;
        stack<int> st;
        vector<bool> visited(n, false);
        vector<bool> inRecurssion(n, false);

        int cnt=0;
        for(int node=0; node<n; node++){
            if(!visited[node] && dfs(node, adj, visited, st, inRecurssion)){
                return {};
            }
        }

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }

    bool dfs(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited, stack<int> &st, vector<bool> &inRecurssion){

        visited[u] = true;
        inRecurssion[u] = true;
        
        for(auto &v : adj[u]){
            if(!visited[v]){ 
                if(dfs(v, adj, visited, st, inRecurssion)){
                    return true;
                }       
            }
            if(inRecurssion[v]){
                return true;
            }
        }

        st.push(u);
        inRecurssion[u] = false;
        return false;
    }
};