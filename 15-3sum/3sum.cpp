class Solution {
public:
    // Brute Force
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> ans;
    //     vector<vector<int>>:: iterator it;

    //     for(int i = 0; i < n; i++){
    //         int firstElement = nums[i];
    //         for(int j = i + 1; j < n; j++){
    //             int secondElement = nums[j];
    //             int diff = -(firstElement + secondElement);
    //             vector<int> vec;
    //             for(int k = j + 1; k < n; k++){
    //                 if(nums[k] == diff) {
    //                     vec.push_back(firstElement);
    //                     vec.push_back(secondElement);
    //                     vec.push_back(diff);
    //                     break;
    //                 }
    //             }
    //             if(!vec.empty()){
    //                 sort(vec.begin(), vec.end());
    //                 it = find(ans.begin(), ans.end(), vec);
    //                 if(it == ans.end()){
    //                     ans.push_back(vec);
    //                 }
    //             }
    //         }
    //     }
    //     return ans;

    vector<vector<int>> threeSum(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // vector<vector<int>> :: iterator it;

        // Base Case
        if(n < 3) return ans;
        
        for(int i = 0; i < n - 2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; // Skip Duplicates
            int target  = -nums[i];
            int left = i + 1;
            int right = n - 1;

            while(left < right){
                if(left > i + 1 && nums[left] == nums[left - 1]){
                    left++;
                    continue;
                } 
                 
                long long sum = nums[left] + nums[right];

                vector<int> result;
                if(sum < target) left++;
                else if(sum > target) right--;
                else{
                    result.push_back(nums[i]);
                    result.push_back(nums[left]);
                    result.push_back(nums[right]);

                    // it = find(ans.begin(), ans.end(), result);
                    // if(it == ans.end()){
                        ans.push_back(result);
                    // }
                    left++;
                }
            }
        }
        return ans;
    }
};