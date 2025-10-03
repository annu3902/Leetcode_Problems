class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row;
        vector<int> col;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for(int i=0; i<row.size(); i++){
            int x = row[i];
            int y = col[i];

            for(int j=0; j<n; j++){
                matrix[x][j] = 0;
            }

            for(int j=0; j<m; j++){
                matrix[j][y] = 0;
            }
        }

    }
};