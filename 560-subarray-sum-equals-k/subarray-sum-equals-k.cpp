class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;
        int count = 0;
        prefix_sum[0] = 1;
        int sum = 0;

        for(int i =0; i<nums.size(); i++){
            sum += nums[i];

            if(prefix_sum.find(sum - k) != prefix_sum.end()){
                count += prefix_sum[sum-k];
            }
            prefix_sum[sum]++;
        }
        return count;
    }
};