class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int maxi = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                sum++;
            }
            else{
                maxi = max(maxi, sum);
                sum = 0;
            }
        }

        if(maxi < sum){
            return sum;
        }

        return maxi;
    }
};