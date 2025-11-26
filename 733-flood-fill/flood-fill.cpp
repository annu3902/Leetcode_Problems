class Solution {
public:
    vector<vector<int>> neighbours{{0,1}, {0,-1}, {1,0}, {-1,0}};

    void dfs(vector<vector<int>>& image, int row, int col, int color, vector<vector<bool>>& visited){
        visited[row][col] = true;

        for(auto &neighbour : neighbours){
            int x = neighbour[0] + row;
            int y = neighbour[1] + col;

            if(x < 0 || y < 0 || x >= image.size() || y >= image[0].size()) continue;
            if(image[x][y] == image[row][col] && visited[x][y] == 0){
                dfs(image, x, y, color, visited);
            }
        }

        image[row][col] = color;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int row, int col, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        visited[row][col] = true;
        dfs(image, row, col, color, visited);

        return image;
    }
};