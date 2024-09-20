class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m-1;

        int ans = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(matrix[mid][0] == target){
                return true;
            }

            if(matrix[mid][0] > target){
                right = mid-1;
            }

            else{
                ans = mid;
                left = mid+1;
            }
        }

        if(ans == -1) return false;

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(matrix[ans][mid] > target){
                high = mid-1;
            }

            else if(matrix[ans][mid] < target){
                low = mid+1;
            }

            else{
                return true;
            }
        }

        return false;
    
    }
};