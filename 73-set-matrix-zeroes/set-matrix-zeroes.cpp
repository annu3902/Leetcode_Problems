// class Solution {
// public:

//     void mark_row(vector<vector<int>> & matrix, int i ){
//         int m =matrix.size();
//         int n =matrix[0].size();

//         for(int j =0; j<n; j++){
//             if(matrix[i][j] == 0){
//                 matrix[i][j] = -1;
//             }
//         }
//         // return;
//     }

//     void mark_col(vector<vector<int>> & matrix, int j){
//         int m = matrix.size();
//         int n = matrix[0].size();

//         for(int i =0; i<m; i++)
//         {
//             if(matrix[i][j] == 0){
//                 matrix[i][j] = -1;
//             }
//         }
//         // return;
//     }

//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         for(int i=0; i<m; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 if(matrix[i][j] == 0){
//                     mark_row(matrix,i);
//                     mark_col(matrix,j);
//                 }
//             }
//         }

//         for(int i =0; i<m; i++)
//         {
//             for(int j =0; j<n; j++)
//             {
//                 if(matrix[i][j] == -1){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//         return;
//     }
// };

class Solution{
public:
   void setZeroes(vector<vector<int>>& matrix){

       int m = matrix.size();
       int n = matrix[0].size();

       vector<int> row(m,0);
       vector<int> col(n,0);

       for(int i=0; i<m; i++){
           for(int j=0; j<n; j++){
               if(matrix[i][j] == 0){
                   row[i] = 1;
                   col[j] = 1;
               }
           }
       }

       for(int i =0; i<m; i++)
       {
           for(int j=0; j<n; j++)
           {
               if(row[i] == 1 || col[j] ==1){
                   matrix[i][j] = 0;
               }
           }
       }


   }
};