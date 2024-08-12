class Solution {
public:
   

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        // unorder
        vector<vector<int>> ans;
        // a + b + c = 0;
        // b + c = -a;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            
            int j = i+1;
            int k = nums.size()-1;

            while(j<k){                
                int sum = nums[j]+nums[k];
                if(sum <= target){
                    if(sum == target) ans.push_back({nums[i] , nums[j] , nums[k]});
                    j++;
                      while(j<k && nums[j] == nums[j-1]) j++;
                    
                }
                else if(sum>target){
                    k--;
                    while(k>j && nums[k] == nums[k+1]) k--;
                }
            }

        }
        return ans;
    }
};

// -4 -1 -1 0 1 2