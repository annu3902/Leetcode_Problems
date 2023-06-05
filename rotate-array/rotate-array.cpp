// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         vector<int> vec;
//         int n =nums.size();
//         k = k%n;
//         for(int i=k; i>0; i--)
//         {
//             vec.push_back(nums[n-i-1]);
//         }

//         for(int i=k; i>=0; i--)
//         {
//             nums[i+3]=nums[i];
//         }

//         for(int i=0; i<k; i++)
//         {
//             nums[i]= vec[i];
//         }
//     }
// };

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};