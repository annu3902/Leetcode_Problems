class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[arr2[i]] = i;
        }

        for(int i=0; i<arr1.size(); i++){
            if(mp.count(arr1[i])) continue;
            mp[arr1[i]] = INT_MAX;
        }

        auto lambda = [&](int num1, int num2){
            if(mp[num1] == mp[num2]) return (num1 < num2);

            return (mp[num1] < mp[num2]);
        };

        sort(begin(arr1), end(arr1), lambda);

        return arr1;
    }
};