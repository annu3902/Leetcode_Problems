class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j =0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};

// class Solution{
// public:
//     bool searchMatrix(vector<vector<int>> & matrix, int target){
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int start =0;
//         int end = m*n -1;
//         while(start < end){
//             int mid = (start+end)/2;
//             // int ele = matrix[i][j];

//             if(target > matrix[mid / n][mid % n]){
//                 start = mid+1;
//             }
//             else if(target < matrix[mid / n][mid % n]){
//                 end = mid-1;
//             }
//             else if(target == matrix[mid/n][mid%n]){
//                 return true;
//             }
//         }
//         return false;
//     }
// }