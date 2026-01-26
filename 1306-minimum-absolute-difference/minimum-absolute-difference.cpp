class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int miniDiff = INT_MAX;

        for(int i=1; i<n; i++){
            int diff = nums[i] - nums[i-1];
            miniDiff = min(miniDiff, diff);
        }
        vector<vector<int>>ans;
        for(int i=1; i<n; i++){
            int diff = nums[i] - nums[i-1];

            if(diff == miniDiff){
                ans.push_back({nums[i-1], nums[i]});
            }
        }
        return ans;

    }
};