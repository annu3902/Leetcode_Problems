class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<edges.size(); i++){
            // edges[0] = {1,2}
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        queue<pair<int, int>> q;
        vector<int> color(n+1, -1);


    for(int i=1; i<=n; i++){
        if(color[i] == -1){
            q.push({i,0});
        }

        while(!q.empty()){
            int size = q.size();

            // while(size--){

                pair<int,int> front = q.front();
                int u = front.first;
                int currColor = front.second;

                color[u] = currColor;
                q.pop();
                cout<<u<<" ";

                currColor = 1 - color[u];

                for(auto &v: adj[u]){
                    if(color[v] == color[u]) return false;

                    else if(color[v] == -1){

                        q.push({v, currColor});
                        color[v] = currColor;

                    }

                }
            // }

        }
    }
        return true;   

    }
};