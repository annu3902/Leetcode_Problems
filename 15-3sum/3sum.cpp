class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = n-1;
            int target = -nums[i];

            while(j < k){
                if(j-1 != i && nums[j] == nums[j-1]){
                    j++;
                    continue;
                }
                if(k < n-1 && nums[k] == nums[k + 1]){
                    k--;
                    continue;
                }
                int sum = nums[j] + nums[k];
                if(sum < target){
                    j++;
                }else if(sum > target){
                    k--;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                }
            }
        }

        return ans;
    }
};