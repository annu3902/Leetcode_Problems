class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;

        // Creation of subarray of size k
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }   
        
        long long maxSum = sum;
        int endIndex = k;
        int startIndex = 0;

        while(endIndex < n){
            sum -= nums[startIndex++];

            sum += nums[endIndex++];

            maxSum = max(maxSum, sum);
        }

        return (double) (maxSum) / k;
    }
};