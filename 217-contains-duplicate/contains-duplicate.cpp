// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int,int> mpp;
        
//         for(int i=0; i<nums.size(); i++)
//         {
//             mpp[nums[i]]++;
//         }

//         for(auto it : mpp)
//         {
//             if(it.second >= 2){
//                 return true;
//                 break;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        for(int j=1; j<nums.size(); j++)
        {
            if(nums[i] != nums[j]){
                i=j;
            }
            else{
                return true;
            }
        }
        return false;
    }
};