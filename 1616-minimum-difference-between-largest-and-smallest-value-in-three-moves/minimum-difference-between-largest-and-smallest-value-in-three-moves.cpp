class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        int  n = nums.size();

        sort(begin(nums), end(nums));

        // for(int i=1; i<=4; i++){
        //     int diff = 
        // }
        int op1 = nums[n-1] - nums[3];
        int op2 = nums[n-2] - nums[2];
        int op3 = nums[n-3] - nums[1];
        int op4 = nums[n-4] - nums[0];

        return min({op1, op2, op3, op4});     
    }
};