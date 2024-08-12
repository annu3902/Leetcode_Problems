class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));

        for(int i=0; i<n; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<n; j++){
                if(j!=i+1 && nums[j] == nums[j-1]) continue;

                long long sum = target - (long long)(nums[i] + nums[j]);

                int k=j+1;
                int l=n-1;

                while(k < l){
                    if(nums[k]+nums[l]<sum) k++;

                    else if(nums[k] + nums[l] == sum){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        while(k < l && nums[k] == nums[k-1]){
                            k++;
                        }
                    }
                    // if(nums[k] + nums[l] <= target){
                    //     if(nums[k] + nums[l] == target)ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    //     k++;
                    //     while(k < l && nums[k] == nums[k-1]){
                    //         k++;
                    //     }
                    // }

                    while(k < l && nums[k] + nums[l] > sum){
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};