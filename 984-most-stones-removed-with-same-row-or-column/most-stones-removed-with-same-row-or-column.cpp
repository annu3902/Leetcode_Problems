class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
            int cntGangs=0;
            vector<bool> visited(n, false);

            for(int i=0; i<n; i++){
                if(!visited[i]){
                    dfs(i, visited, stones);
                    cntGangs++;
                }

            }
        int removedStones = n - cntGangs;
        return removedStones;
    }

void dfs(int index, vector<bool> &visited, vector<vector<int>> &stones){
        visited[index] = true;

        for(int i=0; i<stones.size(); i++){
            int row = stones[i][0];
            int col = stones[i][1];
            if(!visited[i]){
                if(stones[index][0] == row || stones[index][1] == col){
                    dfs(i, visited, stones);
                }
            }
        }
        
        return;
    }
};