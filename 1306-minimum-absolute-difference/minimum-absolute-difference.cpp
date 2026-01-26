class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int n = arr.size();

        int i=0;
        int j=1;
        int mini = INT_MAX;
        map<int, vector<vector<int>>> mp;

        while(j < n){
            if(mini > abs(arr[j] - arr[i])){
                mini = abs(arr[j] - arr[i]);
                mp[mini].push_back({arr[i], arr[j]});
            }else if(mini = abs(arr[j] - arr[i])){
                mp[mini].push_back({arr[i], arr[j]});
            }
            i++; j++;
        }

        auto it = mp.begin();
        vector<vector<int>> ans;
        for(auto v : mp.begin()->second){
            ans.push_back(v);
        }

        return ans;
    }
};