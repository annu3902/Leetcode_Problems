class Solution {
public:
    // if all the courses can be read in that can be visited or not -> Kahn's Algorithm

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        int edges = prerequisites.size();

        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0);
        for(int i=0; i<edges; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        // 1. inDegree Calculation
            inDegree[u]++;
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
        
        cout<<cnt<<" ";
        if(cnt != n) return false;
        return true;

    }
};

/* Cycle Detection using DFS 
class Solution{
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites){
    
        int m = prerequisites.size();
        // Graph form
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<m; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        vector<bool> visited(n, false);
        vector<bool> inRecurssion(n, false);
        int cnt=0;

        for(int i=0; i<n; i++){
            if(!visited[i] && dfs(adj, i, visited, inRecurssion)){
                return false; // if cycle is present we can not visit all, the nodes
            }
        }
        return true;
    }

    bool dfs(unordered_map<int, vector<int>> &adj, int node, vector<bool> &visited, vector<bool> &inRecurssion){

        visited[node] = true;
        inRecurssion[node] = true;

        for(auto &v : adj[node]){
            if(!visited[v] && dfs(adj, v, visited, inRecurssion)){
                return true;
            }
            else if(inRecurssion[v]){
                return true;
            }
        }
        inRecurssion[node] = false;
        return false;
    }   
};
*/