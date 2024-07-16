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

        // if(num >= 10) return; 

        for(int i=num; i<10; i++){
            sum += i;
            temp.push_back(i);
            solve(i+1, k, n, sum, temp, result);

            sum -= i;
            temp.pop_back();
        }
    }
};