class Solution {
private:
    void f(int k, int n, vector<vector<int>> & ans, vector<int> & temp, int number){
        
        if(k == 0 && n == 0){
            ans.push_back(temp);
            return;
        }
        else if(n < 0) return;
        else if(k > 0 && n == 0) return;
        else if(k == 0 && n > 0) return;

        for(int i = number; i <= 9; i++){
            temp.push_back(i);
            f(k-1, n-i, ans, temp, i+1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(k, n, ans, temp, 1);
        return ans;
    }
};