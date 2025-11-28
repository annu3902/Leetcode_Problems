class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int color) {
        int m = image.size();
        int n = image[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        vector<int> offsets = {-1, 0, 1, 0, -1};

        q.push({x, y});

        while(!q.empty()){
            pair<int, int> p = q.front();
            int x0 = p.first;
            int y0 = p.second;
            q.pop();

            for(int i=0; i<4; i++){
                int x1 = x0 + offsets[i];
                int y1 = y0 + offsets[i+1];

                if(x1 < 0 || y1 < 0 || x1 >= m || y1 >= n) continue;

                if(image[x1][y1] == image[x0][y0] && !visited[x1][y1]){
                    q.push({x1, y1});
                    visited[x1][y1] = true;
                } 
            }
            image[x0][y0] = color;
        }

        return image;
    }
};