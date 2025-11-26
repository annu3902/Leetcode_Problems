class Solution {
public:
vector<vector<int>> neighbours{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        visited[i][j] = true;

        vector<vector<int>> neighbours{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(auto &neighbour : neighbours){
            int x = neighbour[0] + i;
            int y = neighbour[1] + j;

            if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) continue;

            else if(grid[x][y] == '1' && !visited[x][y]){
                dfs(grid, x, y, visited);
            }
        }

        return;
    }

    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});

        
        while(!q.empty()){
            int size = q.size();

            while(size--){
                pair<int, int> p = q.front();
                int u = p.first;
                int v = p.second;
                
                
                q.pop();
                for(auto& neighbour: neighbours){
                    int x = u + neighbour[0];
                    int y = v + neighbour[1];

            // Boundry Check
                if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()){
                    continue;
                }

                else if(visited[x][y] == 0 && grid[x][y] == '1'){
                    q.push({x, y});
                    visited[x][y] = true;
                    
                }
            }
            }
 
        }

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    bfs(grid, i, j, visited);
                    count++;
                }
            }
        }

        return count;
    }
};