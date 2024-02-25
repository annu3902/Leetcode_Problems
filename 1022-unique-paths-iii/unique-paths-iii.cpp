class Solution {
public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};

    void solve(int &ans, int cnt, int availablePaths, vector<vector<int>>&grid, vector<vector<int>>&visited, int i, int j, int m, int n){

        if(i<0 || i>=m || j<0 || j>=n) return;
        if(visited[i][j] == 1 || grid[i][j] == -1) return;
        if(grid[i][j]==2){
            cout<<cnt<<endl;
            if(cnt==availablePaths){
                ans++;
            }
            return;
        }

        visited[i][j]=1;
        if(grid[i][j]==0) cnt++;
        for(int k=0; k<4; k++){
            solve(ans, cnt, availablePaths, grid, visited, i+row[k], j+col[k], m, n);
        }
        if(grid[i][j]==0) cnt--;
        visited[i][j]=0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        // count number of paths that starts from staring square and ends to the ending square by walking through each empty square exactly once.

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int availablePaths = 0;
        int x,y;
        int x2,y2;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // Finding the start location
                if(grid[i][j]==1){
                    x=i;y=j;
                    // availablePaths++;
                }
                else if(grid[i][j]==2){
                    x2=i;
                    y2=j;
                }
                else if(grid[i][j]==0){
                    availablePaths++;
                }
            }
        }

        cout<<availablePaths<<endl<<endl;
        int ans=0;
        int cnt=0;
        solve(ans, cnt, availablePaths, grid, visited, x, y, m, n);
        return ans;
    }
};