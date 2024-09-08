class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int> (n, 0));

        if(m*n != original.size()) return {};
        int i = 0;
        int j = 0;

        for(int k=0; k<m; k++){
            while(j < n && i < original.size()){
                result[k][j] = original[i];
                j++;
                i++;
            }
            j=0;
        }

        return result;        
    }
};