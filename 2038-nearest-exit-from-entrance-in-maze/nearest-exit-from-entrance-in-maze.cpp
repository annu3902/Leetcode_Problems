class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<vector<int>> q;
        q.push(entrance);
        maze[entrance[0]][entrance[1]] = '+';
        vector<vector<int>> directions = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            level++;

            while(size--){

                vector<int> front = q.front();
                q.pop();
                
                for(vector<int> dir : directions){
                    int i = front[0] + dir[0];
                    int j = front[1] + dir[1];

                    if(i >= 0 && i<=m-1 && j >= 0 && j <= n-1 && maze[i][j] == '.'){
                        if(i==0 || i==m-1 || j==0 || j==n-1){
                            return level;
                        }

                        q.push({i,j});
                        maze[i][j] = '+';
                    }
                }

            }
        }
        return -1;
    }
};