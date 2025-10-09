class Solution {
private:
    bool binarySearch(vector<int>& nums, int num){
        int n = nums.size();
        // for(int n : nums)cout<<n<<" ";

        int left = 0;
        int right = n-1;
        // int mid=-1;

        while(left <= right){
            int mid = (left + right)/2;

            if(nums[mid] == num) return true;
            else if(num > nums[mid]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

        return false;

    }
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // int left = 0;
        // int right = 0;
        // int top = 0;
        // int bottom = n-1;
        // int rowMid, colMid;
        // int left = 0;
        // int right = m-1;

        // while(top <= bottom){

        // }
        for(int i=0; i<n; i++){
            if(binarySearch(matrix[i], target)) return true;
        }

        return false;

    }
};