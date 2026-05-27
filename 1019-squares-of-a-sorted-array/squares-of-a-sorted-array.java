class Solution {
    public int[] sortedSquares(int[] nums) {
        int left = 0;
        int right = nums.length-1;
        int[] ans = new int[nums.length];
        int k = right;

        while(left <= right){
            int leftElement = nums[left];
            int rightElement = nums[right];
            if(Math.abs(leftElement) >= Math.abs(rightElement)){
                ans[k]= leftElement*leftElement;
                left++;
            }
            else{
                ans[k] = rightElement*rightElement;
                right--;
            }
            k--;
        }
        return ans;
    }
}