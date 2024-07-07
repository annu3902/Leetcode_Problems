class Solution {
public:
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0, -1}, {0, 1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool> (n, 0));
        vector<vector<bool>> atlantic(m, vector<bool> (n, 0));

        for(int i=0; i<m; i++){
            dfs(heights, pacific, i, 0, m, n); // LeftMost edge
            dfs(heights, atlantic, i, n-1, m, n); // RightMost edge
        }

        for(int j=0; j<n; j++){
            dfs(heights, pacific, 0, j, m, n); // topMost edge
            dfs(heights, atlantic, m-1, j, m, n); // bottomMost edge
        }

        vector<vector<int>> ans;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] == true && atlantic[i][j] == true) ans.push_back({i, j});
            }
        }

        return ans;

    }

    void dfs(vector<vector<int>> &heights, vector<vector<bool>>& visited, int row, int col, int m, int n){

        visited[row][col] = true;
        for(auto direction : directions){
            int newRow = row + direction[0];
            int newCol = col + direction[1];

            if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n) continue;
            else if(visited[newRow][newCol]) continue;
            else if(heights[newRow][newCol] < heights[row][col]) continue;

            dfs(heights, visited, newRow, newCol, m, n); 

        }
        return;
    }


};