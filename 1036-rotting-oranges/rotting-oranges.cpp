class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Level Order Traversal
        int m = grid.size();
        int n = grid[0].size();
        bool flag = false;

        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    flag = true;
                }
            }
        }


        vector<int> neighbour = {-1, 0, 1, 0, -1};
        vector<vector<int>> matrix = grid;

        int step = 0;
        while(!q.empty()){
            // int size = q.size();

            // while(size--){
                int x = q.front().first.first;
                int y = q.front().first.second;
                int currStep = q.front().second;
                step = currStep;

                q.pop();

                for(int i=0; i<4; i++){
                    int nx = neighbour[i] + x;
                    int ny = neighbour[i+1] + y;

                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    else{
                        if(matrix[nx][ny] == 1){
                            matrix[nx][ny] = 2;
                            q.push({{nx, ny}, currStep+1});
                        }
                    }
                }
            // }
            
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 1) return -1;
            }
        }

        return step;
    }
};