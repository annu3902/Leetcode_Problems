class Solution {
public:
    bool isValid(int x,int y,int m,int n){
        return (x>=0 && y>=0 && x<m && y<n);
    }
    vector<vector<int>> spiralMatrixIII(int rows,int cols,int rStart,int cStart) {
        vector<vector<int>> array{{rStart,cStart}};
        int n=rows*cols;
        int length=1;
        int x=rStart,y=cStart;

        while(array.size() < n){
            //right side;
            for(int i=1;i<=length;i++){
                if(isValid(x,y+i,rows,cols))
                    array.push_back({x,y+i});
            }
            y += length;
            //down side
            for(int i=1;i<=length;i++){
                if(isValid(x+i,y,rows,cols))
                    array.push_back({x+i,y});
            }
            x += length;
            //left side
            length++;
            for(int i=1;i<=length;i++){
                if(isValid(x,y-i,rows,cols))
                    array.push_back({x,y-i});
            }
            y -= length;
            //Up Side
            for(int i=1;i<=length;i++){
                if(isValid(x-i,y,rows,cols))
                    array.push_back({x-i,y});
            }
            x -= length;
            length++;
        }
        return array;
    }
};