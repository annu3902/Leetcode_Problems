class Solution {
    public int binarySearch(int[] nums, int target, int left, int right){
        int n = nums.length;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                return mid;
            }

            else if(nums[mid] > target){
                right = mid - 1;
            }

            else{
                left = mid + 1;
            }
        }

        return -1;
    }

    public int search(int[] nums, int target) {
        int n = nums.length;

        int left = 0;
        int right = n-1;

        while(left < right){
            int mid = left + (right - left)/2;

            if(nums[mid] > nums[right]){
                left = mid + 1;
            }else{
                right = mid;
            }

            if(left == right){
                // We get the point of rotation
                break;
            }
        }

        left = 0;
        int ans = -1;

        ans = binarySearch(nums, target, left, right-1);
        if(ans != -1) return ans;

        ans = binarySearch(nums, target, right, n-1);
        return ans;
    }
}