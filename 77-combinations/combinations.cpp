class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> result;
        solve(1, n, k, temp, result);
        return result;
    }

    void solve(int num, int n, int k, vector<int> &temp, vector<vector<int>> &result){
        if(temp.size() == k){
            result.push_back(temp);
            return;
        }
        // if(temp.size() > k) return;

        for(int i=num; i<=n; i++){
            temp.push_back(i);
            solve(i+1, n, k, temp, result);

            temp.pop_back();
        }
    }
};