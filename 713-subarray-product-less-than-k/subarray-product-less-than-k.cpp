class Solution {
public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans = 0;
//         int left = 0;
//         int right = 0;
//         int product = 1ll;

//         for(; right < n; right++){
//             product = product*nums[right];

//             while(product >= k){
//                 product = product/nums[left];
//                 left++;

//             }

//             if(product < k){
//                 ans++;
//             }
//         }

//         while(left < right){
//             if(product < k){
//                 ans++;
//             }
//                 product = product/nums[left];
//                 left++;
//         }
//         return ans;
//     }
// };

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();
    if (k <= 1) {
        return 0;
    }

    int ans = 0;
    int left = 0;
    int product = 1;

    for (int right = 0; right < n; right++) {
        product *= nums[right];

        while (product >= k) {
            product /= nums[left];
            left++;
        }

        ans += right - left + 1;
    }

    return ans;
}
};