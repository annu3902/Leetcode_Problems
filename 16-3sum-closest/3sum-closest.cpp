// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         int n =nums.size();
//         int sum = 0;
//         int mini_dist = INT_MAX;
//         int ans = 0;
        // for(int i =0; i<=n-3; i++){
        //     // same set of i;
        //     if(i > 0 && nums[i] == nums[i-1]){
        //         continue;
        //     }
        //     sum = nums[i] + nums[n-1];
        //     for(int j =i+1; j<=n-2; j++){
        //         if(j > i+1 && nums[j] == nums[j-1]){
        //             continue;
        //         }
        //         else if(j==i+1){
        //             sum += nums[j];
        //         }
        //         else{
        //             int diff = nums[j] - nums[j-1];
        //             sum += diff;
        //         }
        //         int gap = abs(target - sum);
        //         if(gap > mini_dist){
        //             break;
        //         }
        //         else if(gap < mini_dist){
        //             // Ans Case
        //             mini_dist = gap;
        //             ans = sum;
        //         }
        //         else if(gap == mini_dist && sum == target){
        //             mini_dist = gap;
        //             ans = sum;
        //         }
        //     }
        // }
        // return ans;
        
//     }
// };


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n =nums.size();
        int mini =INT_MAX;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i =0; i<n; i++){
            // if(i > 0 && nums[i] == nums[i-1]){
            //     continue;
            // }
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(target - sum);
                if(diff < mini){
                    mini = diff;
                    ans = sum;
                }
        //         j++;    
                if(sum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};