class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int maxSum = 0;
        int sum = 0;

        if(k==n) return maxSum = accumulate(nums.begin(), nums.end(), 0);

        int leftSum = 0;
        int rightSum = 0;
        int i=0;

        for(; i<k; i++){
            leftSum += nums[i];
        }
        i--;
        
        maxSum = leftSum;

        int j=n-1;
        for(int i=k-1; i>=0; i--){

            leftSum -= nums[i];
            rightSum += nums[j];
            j--;

            sum = leftSum + rightSum;

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};