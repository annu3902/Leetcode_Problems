class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int groups = 0;
        int n = stones.size();

        vector<bool> visited(stones.size(), false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(stones, visited, i);
                groups++;
            }
        }

        return (n - groups);
    }

    void dfs(vector<vector<int>> &stones, vector<bool> &visited, int u){

        visited[u] = true;
        int row = stones[u][0];
        int col = stones[u][1];

        for(int v=0; v<stones.size(); v++){
            if(!visited[v] && (stones[v][0] == row || stones[v][1] == col)){
                dfs(stones, visited, v);
            }
        }
    }
};