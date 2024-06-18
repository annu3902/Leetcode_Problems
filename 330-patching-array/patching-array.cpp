class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch = 0;

        long long maxRange = 0;
        int i = 0;
        while(maxRange < n){
            if(i < nums.size() && nums[i] <= maxRange + 1){
                maxRange = maxRange + nums[i];
                i++;
            }
            else{
                maxRange += maxRange + 1;
                patch++;
            }

        }

        return patch;
    }
};