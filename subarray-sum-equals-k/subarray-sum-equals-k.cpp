// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int sum =0; 
//         int cnt =0;
//         map<int, int > mpp;
//         // mpp[0] = -1;
//         for(int i=0; i<nums.size(); i++)
//         {
//             sum = sum + nums[i];
//             if(sum == k){
//                 cnt++;
//             }
//             int rem = sum - k;
//             if(rem !=0){
//                 if(mpp.find(rem) != mpp.end()){
//                     cnt++;
//                 }
//             }
//             if(mpp.find(sum) == mpp.end()){
//                 mpp[sum] = i;
                
//             }
//             // if(sum == 0){
//             //     mpp[sum] = i;
//             // }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0; 
        int cnt = 0;
        unordered_map<int, int> freq;
        freq[0] = 1; // To handle cases when sum == k
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (freq.count(sum - k)) {
                cnt += freq[sum - k];
            }
            freq[sum]++;
        }
        return cnt;
    }
};