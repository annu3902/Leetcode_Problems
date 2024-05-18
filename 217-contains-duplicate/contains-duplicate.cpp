class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;    
        for(int i=0; i<nums.size(); i++)
        {
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]);
            }
            else {
                return true;
            }
        }

        return false;
    }
};

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int i=0;
//         for(int j=1; j<nums.size(); j++)
//         {
//             if(nums[i] != nums[j]){
//                 i=j;
//             }
//             else{
//                 return true;
//             }
//         }
//         return false;
//     }
// };