class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Level Order Traversal
        int m = grid.size();
        int n = grid[0].size();
        bool flag = false;

        queue<pair<int, int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    flag = true;
                }
            }
        }

        

        vector<int> neighbour = {-1, 0, 1, 0, -1};
        vector<vector<int>> matrix = grid;

        int ans = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;

                for(int i=0; i<4; i++){
                    int nx = neighbour[i] + x;
                    int ny = neighbour[i+1] + y;

                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    else{
                        if(matrix[nx][ny] == 1){
                            matrix[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            ans++;
            
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 1) return -1;
            }
        }

        if(flag == false){
            // if flag is false i do not need to go inside processor
            return 0;
        }

        return ans-1;
    }
};