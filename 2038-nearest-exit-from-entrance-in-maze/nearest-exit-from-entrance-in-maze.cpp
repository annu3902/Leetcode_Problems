class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {0,1}, {-1,0}, {1,0}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<vector<int>> q;
        q.push(entrance);

        int entranceRow = entrance[0];
        int entranceCol = entrance[1];

        int level = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){

                vector<int> frontNode = q.front();
                q.pop();
                int row = frontNode[0];
                int col = frontNode[1];

                if(row == 0 || row == m-1 || col == 0 || col == n-1){
                    if(row != entranceRow || col != entranceCol) return level;
                }

                maze[row][col] = '+';

                for(vector<int> &vec : directions){
                    int newRow = row + vec[0];
                    int newCol = col + vec[1];

                    if(newRow >= 0 && newRow <= m-1 && newCol >= 0 && newCol <= n-1 && maze[newRow][newCol] == '.'){
                        q.push({newRow, newCol});
                        maze[newRow][newCol] = '+';
                    }

                    // else if()
                }

            }

            level++;

        }

        return -1;

    }
};