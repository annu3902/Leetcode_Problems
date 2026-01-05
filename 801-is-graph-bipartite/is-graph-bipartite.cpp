class Solution {
private:
    bool bfs(int node, int currColor, vector<vector<int>>& graph, vector<int>& color){
        queue<pair<int, int>> q;
        q.push({node, currColor});

        while(!q.empty()){
            int node = q.front().first;
            int currColor = q.front().second;
            color[node] = currColor;
            q.pop();

            for(auto& v :graph[node]){
                if(color[v] == -1){
                    q.push({v, 1-currColor});
                }
                else if(color[v] == currColor) return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            if(color[i] == -1 && bfs(i, 0, graph, color) == false){
                return false;
            }
        }

        return true;
    }
};