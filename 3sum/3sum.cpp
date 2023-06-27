// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         sort(nums.begin(),nums.end());
//         int n =nums.size();
//         for(int i=0; i<n; i++)
//         {
//             int sum = -nums[i];
//             map<int,int> mpp;
//                 vector<int> temp;
//             for(int j=i+1; j<n; j++){
//                 if(mpp.find(sum - nums[j]) != mpp.end()){
//                     temp.push_back(nums[i]);
//                     temp.push_back(sum - nums[j]);
//                     temp.push_back(nums[j]);
//                 ans.push_back(temp);
//                 temp.clear();
//                     // break;
//                 }
//                 mpp[nums[j]]++;
//             }
//         }
//         set<vector<int>> st;
//         for(int i=0; i<ans.size(); i++)
//         {
//             st.insert(ans[i]);
//         }

//         vector<vector<int>> anss;
//         for(auto it : st){
//             anss.push_back(it);
//         }
        
//         return anss;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target = -nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // Skip duplicates
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};