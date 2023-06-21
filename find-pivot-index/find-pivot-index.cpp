// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> prefix(n+1, 0);
//         int ans = -1;
//         for(int i=0; i<n; i++)
//         {
//             prefix[i+1] = prefix[i]+nums[i];
//         }

//         for(int i=0; i<n; i++)
//         {
//             if(prefix[i] == prefix[n] - prefix[i+1]){
//                 ans =i;
//                 break;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n =nums.size();
        vector<int> ls(n);
        int ts =0;
        int ans = -1;

        for(int i=0; i<n; i++)
        {
            ts += nums[i];
            ls[i] = ts -nums[i];
        }

        for(int i=0; i<n; i++)
        {
            int rs = ts - ls[i] - nums[i];
            if(rs == ls[i]){
                ans = i;
                break;
            }
        }
        return ans;
    }
 };
