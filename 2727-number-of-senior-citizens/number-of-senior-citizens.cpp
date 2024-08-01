class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        int n = details.size();

        for(int i=0; i<n; i++){
            if(details[i][11] > '6' && details[i][12] >= '0') ans++;
            else if(details[i][11] == '6' && details[i][12] >= '1') ans++;
        }

        return ans;
    }
};