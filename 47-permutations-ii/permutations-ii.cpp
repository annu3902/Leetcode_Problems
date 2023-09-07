// class Solution {
// public:
//     void recursion(vector<int> num, int i, int n, vector<vector<int> > &result) {
//         if(i == n-1){
//             result.push_back(num);
//             return;
//         }

//         for(int k = i; k < n; k++){
//             if(k != i && num[k] == num[i]) continue;

//             swap(num[k], num[i]);
//             recursion(num, i+1, n, result);
//         }
//     }
//     vector<vector<int> > permuteUnique(vector<int> &num) {
//         sort(num.begin(), num.end());

//         int n = num.size();

//         vector<vector<int>> result;
//         recursion(num, 0, n, result);
        
//         return result;
//     }
// };


class Solution {
public:
    void permutation_generator(vector<int> nums, int pos, vector<vector<int>>& ans){

        if(pos == nums.size()-1){
            vector<vector<int>> :: iterator it;
            it = find(ans.begin(),ans.end(),nums);
            if(it==ans.end())   ans.push_back(nums);
            return;
        }

        for(int i=pos; i<nums.size(); i++){
            swap(nums[i], nums[pos]);
            permutation_generator(nums, pos+1, ans);
            // swap(nums[i] , nums[pos]);
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        permutation_generator(nums, 0, ans);
        // sort(ans.begin(), ans.end());
        return ans;
    }
};