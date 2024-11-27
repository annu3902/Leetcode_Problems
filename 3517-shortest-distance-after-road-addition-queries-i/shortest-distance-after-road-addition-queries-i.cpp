class Solution {
public:
    
    int bfs(unordered_map<int, vector<int>>& adj, vector<bool> visited, int n){
        
        int level = 0;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        bool flag = false;
        
        while(!q.empty()){
            
            int size = q.size();
            while(size--){
                
                int frontNode = q.front();
                q.pop();
                if(frontNode == n-1) return level;
                visited[frontNode] = true;
                
                for(auto& it : adj[frontNode]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
            level++;            
        }
        
        return -1;
        
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        
        for(int i=0; i<n-1; i++){
            adj[i].push_back(i+1);
        }
        
        vector<int> result;
        vector<bool> visited(n, false);
        
        for(vector<int>& query : queries){
            int u = query[0];
            int v = query[1];
            
            adj[u].push_back(v);
            
//                 for(auto it : adj){
//                     cout<<it.first<<" -> ";
//                 for(auto i : it.second){
//                     cout<<i<<" ";
//                 }
//                     cout<<endl;
//                 }
            
//             cout<<endl<<endl<<endl;
            
            int ans = bfs(adj, visited, n);
            result.push_back(ans);            
        }
        
        return result;
    }
};