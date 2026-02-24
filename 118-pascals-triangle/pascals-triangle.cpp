class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> matrix(n);

        for(int i = 0; i < n; i++){
            vector<int> temp(i + 1, 0);

            for(int j = 0; j <= i; j++){
                if(j == 0) temp[j] = 1;
                else if(j <= i-1){
                    temp[j] = matrix[i-1][j] + matrix[i-1][j-1];
                }
                else{
                    temp[j] = 1;
                }
            }
            matrix[i] = (temp);
        }

        return matrix;
    }
};