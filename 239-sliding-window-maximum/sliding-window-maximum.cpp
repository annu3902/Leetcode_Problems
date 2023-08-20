// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n =nums.size();
//         int i =0;
//         int j=0;
//         list <int> ls;
//         int maxi =INT_MIN;
//         vector<int> ans;

//         while(j < n){
//             while(ls.size() > 0 && ls.back() < nums[j]){
//                 ls.pop_back();
//             }
//                 ls.push_back(nums[j]);

//             if(j - i +1 <k){
//                 j++;
//             }

//             else if(j -i +1 == k)
//             {
//                 ans.push_back(ls.front());
//                 maxi = ls.front();

//                 if( nums[i] == maxi){
//                     ls.pop_front();
//                 }

//                 i++;
//                 j++;
//             }
//         }
//         return ans;
//     }
// };

// // class Solution {
// // public:
// //     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
// //         int n = nums.size();
// //         int i = 0;
// //         int j = 0;
// //         list<int> ls;
// //         vector<int> ans;

// //         while (j < n) {
// //             while (!ls.empty() && ls.back() < nums[j]) {
// //                 ls.pop_back();
// //             }
// //             ls.push_back(nums[j]);

// //             if (j - i + 1 < k) {
// //                 j++;
// //             } else if (j - i + 1 == k) {
// //                 ans.push_back(ls.front());

// //                 if (nums[i] == ls.front()) {
// //                     ls.pop_front();
// //                 }

// //                 i++;
// //                 j++;
// //             }
// //         }

// //         return ans;
// //     }
// // };

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        
        vector<int> ans;
        int i =0;
        int j =0;
        int n =nums.size();
        list<int> ls;
        
        while(j < n){
            // Add calcultaions for nums[j]
            while(!ls.empty() && ls.back() < nums[j]){
                ls.pop_back();
            }

            ls.push_back(nums[j]);

            if(j-i+1 < k){
                j++;
            }

            else if(j-i+1 == k){
                // ans calculation
                ans.push_back(ls.front());


                // remove calculations for nums[i]
                if(nums[i] == ls.front()){
                    ls.pop_front();
                }


                // Slide the window
                i++;
                j++;
            }
        }
        return ans;
    }
};