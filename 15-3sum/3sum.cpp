// // // class Solution {
// // // public:
// // //     vector<vector<int>> threeSum(vector<int>& nums) {
// // //         vector<vector<int>> ans;
// // //         sort(nums.begin(),nums.end());
// // //         int n =nums.size();
// // //         for(int i=0; i<n; i++)
// // //         {
// // //             int sum = -nums[i];
// // //             map<int,int> mpp;
// // //                 vector<int> temp;
// // //             for(int j=i+1; j<n; j++){
// // //                 if(mpp.find(sum - nums[j]) != mpp.end()){
// // //                     temp.push_back(nums[i]);
// // //                     temp.push_back(sum - nums[j]);
// // //                     temp.push_back(nums[j]);
// // //                 ans.push_back(temp);
// // //                 temp.clear();
// // //                     // break;
// // //                 }
// // //                 mpp[nums[j]]++;
// // //             }
// // //         }
// // //         set<vector<int>> st;
// // //         for(int i=0; i<ans.size(); i++)
// // //         {
// // //             st.insert(ans[i]);
// // //         }

// // //         vector<vector<int>> anss;
// // //         for(auto it : st){
// // //             anss.push_back(it);
// // //         }
        
// // //         return anss;
// // //     }
// // // };


// // class Solution {
// // public:
// //     vector<vector<int>> threeSum(vector<int>& nums) {
// //         vector<vector<int>> ans;
// //         sort(nums.begin(), nums.end());
// //         int n = nums.size();
// //         for (int i = 0; i < n; i++) {
// //             // Skip duplicates
// //             if (i > 0 && nums[i] == nums[i-1]) {
// //                 continue;
// //             }
// //             int target = -nums[i];
// //             int left = i + 1, right = n - 1;
// //             while (left < right) {
// //                 int sum = nums[left] + nums[right];
// //                 if (sum == target) {
// //                     ans.push_back({nums[i], nums[left], nums[right]});
// //                     // Skip duplicates
// //                     while (left < right && nums[left] == nums[left+1]) left++;
// //                     while (left < right && nums[right] == nums[right-1]) right--;
// //                     left++;
// //                     right--;
// //                 } else if (sum < target) {
// //                     left++;
// //                 } else {
// //                     right--;
// //                 }
// //             }
// //         }
// //         return ans;
// //     }
// // };

// // class Solution {
// // public:
// //     vector<vector<int>> threeSum(vector<int>& nums) {
// //         vector<vector<int>> ans;
// //         sort(nums.begin(),nums.end());
// //         set<int> st;
// //         int n = nums.size();
// //         for(int i=0; i<n; i++) {
// //             int sum = -nums[i];
// //             set<int> s;
// //             vector<int> temp;
// //             for(int j=i+1; j<n; j++) {
// //                 if(s.count(sum - nums[j])) {
// //                     temp.push_back(nums[i]);
// //                     temp.push_back(sum - nums[j]);
// //                     temp.push_back(nums[j]);
// //                     if(!count(ans.begin(),ans.end(),temp))
// //                     ans.push_back(temp);
// //                     temp.clear();
// //                 }
// //                 s.insert(nums[j]);
// //             }
// //         }
// // 
// //         return ans;
// //     }
// // };

// // class Solution{
// //     public:
// //     vector<vector<int>> threeSum(vector<int> &nums){
// //         sort(nums.begin(),nums.end());
// //         vector<vector<int>> ans;
// //         int n =nums.size();

// //         for(int i=0; i<n; i++)
// //         {
// //             if(i>0 && nums[i] == nums[i-1]){
// //                 continue;
// //             }

// //             int left =i+1;
// //             int right =n-1;
// //             int target = -nums[i];

// //             while(left< right){


// //                 int sum = nums[left] +nums[right];
// //                 if(sum == target){
// //                     ans.push_back({ nums[i],nums[left],nums[right]});
// //                     // ans.push_back(nums[right]);
// //                     // ans.push_back(nums[i]);
// //                     while(left <right && nums[left] == nums[left+1]) {
// //                         left++;
// //                     }

// //                     while(left <right && nums[right] == nums[right-1]){
// //                         right--;

// //                     }
// //                     left++;
// //                     right--;
// //                 }

// //                 else if(sum < target){
// //                     left++;
// //                 }

// //                 else{
// //                     right--;
// //                 }
// //             }
// //         }
// //         return ans;
// //     }
// // };


// class Solution{
//     public:
//     vector<vector<int>> threeSum(vector<int>& nums){
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         vector<int> v;
//         int low = 0;
//         int n = nums.size();
//         int high = n-1;
//         while(low < high){
//             int mid = (low + high)/2;
//             int target = 0 - (nums[low] + nums[high]);

//             if(nums[mid] == target){
//                 v.push_back(nums[low]);
//                 v.push_back(nums[high]);
//                 v.push_back(nums[mid]);
//                 ans.push_back(v);
//                 v.clear();
//             }

//             else if(nums[mid] > target){
//                 high = mid - 1;
//             }
//             else{
//                 low = mid + 1;
//             }
//         }
//         return ans;
//     }
// };

class Solution{
    public:
    vector<vector<int>> threeSum(vector<int>& nums){
       int n =nums.size();
       sort(nums.begin(), nums.end()); 
       int i = 0;
       vector<vector<int>> ans;
      for(int i=0;i<n;i++){
           if(i > 0 && nums[i] == nums[i-1]){
               continue;
           }
           int j = i+1;
           int k = n -1;
           while(j < k){
               int sum = nums[j] + nums[k] + nums[i];
               if(sum == 0){
                   ans.push_back({nums[i], nums[j], nums[k]});
                   j++;
                   k--;
                   while(j < k && nums[j] == nums[j-1]){
                       j++;
                   }
                   while(j< k && nums[k] == nums[k+1]){
                       k--;
                   }
               }
               else if(sum < 0){
                   j++;
               }
               else{
                   k--;
               }
           }
        //    i++;
       }
       return ans;
    }
};
