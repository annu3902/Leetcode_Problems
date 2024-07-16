class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> result;

        solve(1, k, n, 0, temp, result);
        return result;
    }

    void solve(int num, int k, int n, int sum, vector<int> &temp, vector<vector<int>> &result){
        if(temp.size() == k){
            if(sum == n){
                result.push_back(temp);
            }
            return;
        }

        if(num >= 10) return; 

        sum += num;
        temp.push_back(num);
        solve(num+1, k, n, sum, temp, result);

        sum -= num;
        temp.pop_back();
        solve(num+1, k, n, sum, temp, result);
    }
};