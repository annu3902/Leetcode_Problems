class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> distance(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        vector<int> vicinity = {-1, 0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;

            visited[row][col] = true;
            q.pop();

            for(int i=0; i<4; i++){
                int x = row + vicinity[i];
                int y = col + vicinity[i+1];

                if(x<0 || y<0 || x>=m || y>=n) continue;

                else if(visited[x][y] == false){
                    visited[x][y] = true;
                    q.push({{x,y}, dist+1});
                }
            }
            distance[row][col] = dist;

        }

        return distance;
    }
};