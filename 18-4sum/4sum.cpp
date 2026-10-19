class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(begin(nums), end(nums));
        int i = 0;
        int j = n-1;

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1; j<n; j++){
                if(j != i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                long long sum = nums[i] + nums[j];
                long long newTarget = target - sum;

                int k = j+1;
                int l = n-1;

                while(k < l){
                    if(k != j+1 && nums[k] == nums[k-1]){
                        k++;
                        continue;
                    }else if(l < n-1 && nums[l] == nums[l+1]){
                        l--;
                        continue;
                    }
                    if(nums[k] + nums[l] < newTarget){
                        k++;
                    }else if(nums[k] + nums[l] > newTarget){
                        l--;
                    }else{
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        // l--;
                    }
                }
            }
        } 
        return ans;
    }
};