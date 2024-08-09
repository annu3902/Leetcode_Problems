class Solution {
private:
    bool checkSquare(vector<vector<int>>& grid , int i , int j){
        vector<bool> visited(16 , false);

        for(int x=i;x<i+3;x++){
            for(int y=j ; y<j+3 ; y++){
                if(visited[grid[x][y]]==true || grid[x][y] <=0 || grid[x][y] >9 ){
                    return false;
                }
                else{
                    visited[grid[x][y]] = true;
                }
            }
        }

        int sum = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];

        if(sum != grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j]) return false;

        int currsum=0;

        for(int x=0 ; x<3 ; x++){
            currsum =0;
            for(int y=0 ; y<3 ; y++){
                currsum += grid[i+x][j+y];
            }
                
            if(sum!= currsum) return false;
        }

        for(int x=0 ; x<3 ; x++){
            currsum =0;
            for(int y=0 ; y<3 ; y++){
                currsum += grid[i+y][j+x];
            }
            
            if(sum!= currsum) return false;
        }

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(rows*cols < 9 || rows<3 || cols<3){
            return 0;
        }

        int ans=0;

        for(int i=0 ; i <=cols-3 ; i++){
            for(int j=0 ; j<= rows-3 ; j++){
                if(checkSquare(grid , j ,i)){
                    ans++;
                }
            }
        }
        return ans;
    }
};