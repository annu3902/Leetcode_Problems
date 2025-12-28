class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> distance(m, vector<int>(n , -1));
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    distance[i][j] = 0;
                    visited[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }

        vector<int> neighbour = {-1, 0, 1, 0, -1};

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;

            int dist = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nx = x + neighbour[i];
                int ny = y + neighbour[i+1];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                else{
                    if(distance[nx][ny] == -1){
                        visited[nx][ny] = true;
                        distance[nx][ny] = dist+1;
                        q.push({{nx, ny}, dist+1});
                    }
                    else if(visited[nx][ny] == true){
                        distance[nx][ny] = min(distance[nx][ny], dist+1);
                    }
                }
            }
        }

        return distance;
    }
};