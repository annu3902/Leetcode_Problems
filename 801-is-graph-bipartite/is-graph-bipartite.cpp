// class Solution {
// public:
    /*  Checking Bipartite using DFS

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        // To check if we can divide the element of edge in 2 different nodes -> By colouring it with two different colours

        // 1 - > Red
        // 2 - > Blue
        vector<int> color(n,-1);

        for(int node=0; node<n; node++){

            if(color[node] == -1 && dfsBipartite(node, graph, color, 1) == false){
                return false;
            }
        }

        return true;
    }

    bool dfsBipartite(int node, vector<vector<int>> &graph, vector<int> &color, int currColor){

        color[node] = currColor;

        currColor = 1-currColor;
        for(auto &v : graph[node]){
            if(color[v] == color[node]) return false;
            
            else if(color[v] == -1 && dfsBipartite(v, graph, color, currColor) == false){
                return false;
            }
        }

        return true;
    }
};

*/


class Solution{
public:
    bool isBipartite(vector<vector<int>>& graph){

        int n=graph.size();
        vector<int> color(n, -1);

        for(int node=0; node<n; node++){
            if(color[node] == -1 && bfsBipartite(node, graph, color, 0) == false){
                return false;
            }

        }

        return true;
    }

    bool bfsBipartite(int node, vector<vector<int>> &graph, vector<int> &color, int currColor){

        color[node] = currColor;
        queue<pair<int, int>> q;
        q.push({node, currColor});

        while(!q.empty()){
            pair<int, int> frontNode = q.front();
            int u = frontNode.first;
            int clr = frontNode.second;
            q.pop();

            for(auto &v : graph[u]){
                if(color[v] == clr) return false;

                if(color[v] == -1){
                    color[v] = 1-clr;
                    q.push({v, color[v]});
                }
            }
        }
        return true;

    }

};