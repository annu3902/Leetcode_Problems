// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int i =0;
//         int j =0;
//         int sum =nums[0];
//         int min_len =INT_MAX;
//         int n =nums.size();
//         int flag =0;

//         while(i < n)
//         {
//             while(j<i && sum > target){
//                 sum -= nums[j];
//                 j++;
//             }

//             // if(sum >= target){
//             //     min_len = min(min_len, i-j+1);
//             //     sum -= nums[j];
//             //     j++;
//             //     // flag =1;
//             // }
//             // else{
//             //     i++;
//             //     if(i < n){
//             //     sum += nums[i];
//             //     }
//             // }

//             if (sum < target) { 
//                 i++;
//                 if (i < n) { 
//                     sum += nums[i];
//                 }
//             }
//             else { 
//                 min_len = min(min_len, i - j + 1);
//                 sum -= nums[j];
//                 j++;
//             }
//         }

//         // while(j<i && sum> target){
//         //     sum -= nums[j];
//         //     j++;
//         //     min_len = min(min_len, i-j);
//         //     if(sum < target) {
//         //         min_len = i-j+1;
//         //     }
//         // }

//         return min_len == INT_MAX ? 0: min_len;
//         // if(flag ==1) {return min_len;}
//         // else return 0;
//     }
// };


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0; // Initialize to 0
        int min_len = INT_MAX; // Initialize to a large value
        int n = nums.size();

        while (i < n) {
            sum += nums[i];

            while (sum >= target) { // Change > to >=
                min_len = min(min_len, i - j + 1);
                sum -= nums[j];
                j++;
            }

            i++;
        }
        
        return min_len == INT_MAX ? 0 : min_len; // Return 0 if no subarray found
    }
};