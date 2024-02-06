class Solution {
private:
    void solve(int ind, vector<int>& candidates, vector<int>& temp,
               vector<vector<int>>& ans, int sum, int target){
                   // Base Case;
                   if(sum > target) {
                       for(int x : temp){
                           cout<<x<<" ";
                       }
                       cout<<endl;
                       return;
                   }
                   if(sum == target){
                       for(int x : temp){
                           cout<<x<<" ";
                       }
                       cout<<endl;
                        ans.push_back(temp);
                       return;
                   }

                   // Processing
                    for(int i = ind; i < candidates.size(); i++){
                        int flag = 0;
                        while(i<candidates.size() && i != ind && candidates[i] == candidates[i-1]){
                            i++;
                            flag = 1;
                        }
                        if(flag==1) {
                            i--;
                             continue;
                        }
                        // if(i != ind && candidates[i] == candidates[i-1]) continue;
                        temp.push_back(candidates[i]);
                        sum += candidates[i];
                        solve(i+1, candidates, temp, ans, sum, target);
                        sum -= candidates[i];
                        temp.pop_back();
                    }
               } 
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                              int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, candidates, temp, ans, 0, target);
        return ans;
    }
};