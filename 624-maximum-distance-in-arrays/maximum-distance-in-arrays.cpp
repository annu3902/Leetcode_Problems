class Solution {
public:
    int maxDistance(vector<vector<int>>& nums) {
        int m = nums.size();
        int mini1 = nums[0][0];
        int maxi1 = nums[0].back();

        int result = INT_MIN;

        for(int i=1; i<m; i++){
            int mini2 = nums[i][0];
            int maxi2 = nums[i].back();

            int op1 = abs(maxi1 - mini2);
            int op2 = abs(maxi2 - mini1);

            mini1 = min(mini1, mini2);
            maxi1 = max(maxi1, maxi2);

            result = max({result, op1, op2});
        }

        return result;
    }
};