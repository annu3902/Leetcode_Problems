class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;

        int n = arr.size();

        vector<int> prefix = arr;

        for(int i=1; i<n; i++){
            prefix[i]^=prefix[i-1];
        }

        for(auto query : queries){
            int left = query[0];
            int right = query[1];

            if(left == right){
                result.push_back(arr[left]);
            }

            else{
                int ans = prefix[right];

                ans = (left == 0) ? ans : ans ^ prefix[left-1];      
                result.push_back(ans);
            }

        }

        return result;
    }
};