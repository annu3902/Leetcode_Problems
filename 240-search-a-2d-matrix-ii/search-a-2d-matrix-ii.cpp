// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         // This approach gives TLE 
//         // int m = matrix.size();
//         // int n = matrix[0].size();
//         // int low = 0;
//         // int high = m*n - 1;
//         // int mid = low + (high - low)/2;
//         // while(low <= high){
//         //     int row = mid / n;
//         //     int col = mid % n;

//         //     if(matrix[row][col] == target ) return true;
//         //     else if(matrix[row][col] > target){
//         //         high = mid-1;
//         //     }
//         //     else{
//         //         low = mid+1;
//         //     }
//         //     // mid = low + (high - low)/2;
//         // }
//         // return false;

//         int m = matrix.size();
//         int n = matrix[0].size();

//         int row = 0;
//         int col = n-1;
//         while(row < m && col>=0){
//             if(matrix[row][col] == target){
//                 return true;
//             }

//             else if(matrix[row][col] > target){
//                 col--;
//             }

//             else if(matrix[row][col] < target){
//                 row++;
//             }
//         }
//         return false;

//     }
// };

class Solution{
public:
    bool searchMatrix(vector<vector<int>> & matrix, int target){
        int m = matrix.size();
        for(int i=0; i<m; i++)
        {
            if(binary_search(matrix[i].begin(), matrix[i].end(), target)){
                return true;
            }
        }
        return false;
    }
};