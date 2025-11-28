class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> ans = grid; // Also works as a visited vector

        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(ans[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        vector<int> vicinity = {-1, 0, 1, 0, -1};
        bool flag=false;
        while(!q.empty()){
            flag = true;
            int size = q.size();
            count++;
            while(size --){
                pair<int, int> p = q.front();
                int x = p.first;
                int y = p.second;
                q.pop();

                for(int i=0; i<4; i++){
                    int x1 = x + vicinity[i];
                    int y1 = y + vicinity[i+1];

                    if(x1<0 || y1<0 || x1>=m || y1>=n) continue;
                    if(ans[x][y] == 2 && ans[x1][y1] == 1){
                        q.push({x1, y1});
                        ans[x1][y1] = 2;
                    }
                }

            }
        }
        // if(!flag) return 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(ans[i][j] == 1){
                    return -1;
                }
            }
        }

        if(flag == false) return 0;
        return count-1;
    }
};