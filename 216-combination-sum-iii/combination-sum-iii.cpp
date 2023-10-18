class Solution {
public:
    void helper(int ind, int k, int n, vector<bool> &taken, vector<int> &subset, vector<vector<int>> &ans){

        // Base Condition
        if(k == 0){
            if(n == 0) ans.push_back(subset);
            return;
        }

        if(n < 0) return; // Optimization

        for(int i=ind; i <= 9; i++){
            if(i > n) break; // Optimizaion
            if(!taken[i]){
                taken[i] = 1;
                subset.push_back(i);
                helper(i +1, k-1, n-i, taken, subset, ans);
                subset.pop_back();
                taken[i] = 0;
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        vector<vector<int>> ans;
        vector<bool> taken(10,0);
        helper(1, k, n, taken, subset, ans);
        return ans;
    }
};