class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {  
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> freshLocations;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                }
                else if(grid[i][j] == 1){
                    freshLocations.push_back({i, j});
                }
            }
        }

        vector<vector<int>> directions = {{-1,0}, {1,0}, {0, -1}, {0, 1}};

        int levels = 0;
        while(!q.empty()){
            int size = q.size();

            while(size -- ){

                pair<int, int> curr = q.front();
                int u = curr.first;
                int v = curr.second;
                grid[u][v] = 2;

                q.pop();

                for(vector<int> &dir : directions){

                    int i = curr.first + dir[0];
                    int j = curr.second + dir[1];

                    if(i >= 0 && i <= m-1 && j >= 0 && j <= n-1 && grid[i][j] == 1){

                        q.push({i, j});
                        grid[i][j] = 2;

                    }

                }
            }
            levels++;
        }

        for(vector<int> vec : freshLocations){
            if(grid[vec[0]][vec[1]] == 1) return -1;
        }
        
        int ans = (levels == 0) ? 0 : levels-1;
        return ans;

    }
};