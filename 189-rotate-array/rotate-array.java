class Solution {
    public void rotate(int[] nums, int k) {
        int[] temp = new int[k];
        int n = nums.length;
        if(n < k) k = k % n; 

    // Step1 - Store k elements in temp array
        for(int i=n-k; i<=n-1; i++){
            temp[i-(n-k)] = nums[i];
        }   

    // Step2 - Right Shift by k position
        for(int i=n-k-1; i>=0; i--){
            nums[i+k]= nums[i];
        }

    // Step3 - Copy the K elements to start
        for(int i=0; i<k; i++){
            nums[i] = temp[i];
        }

    }
}