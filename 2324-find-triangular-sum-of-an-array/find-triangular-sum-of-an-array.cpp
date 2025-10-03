class Solution {
public:
    int triangularSum(vector<int>& nums) {
       int n = nums.size();
       
        if(n == 1) return nums[0];

        for(int i=1; i<n; i++){

            vector<int> temp(n-i, 0);
            for(int j=0; j<nums.size()-1; j++){

                temp[j] =( nums[j] + nums[j+1]) % 10;
                
            }
            nums = temp;

        }
        return nums[0];
    }
};