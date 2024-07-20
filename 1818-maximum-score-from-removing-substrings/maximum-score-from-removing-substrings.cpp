class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        if(n == 1) return 0;

        string maxStr = (x >= y) ? "ab" : "ba";
        int maxInt = (x >= y )? x : y;
        string minStr = (x < y )? "ab" : "ba";
        int minInt = (x < y) ? x : y;

        int count1 = solve(s, maxStr, maxInt);
        int count2 = solve(s, minStr, minInt);

        cout<<count1<<" "<<count2<<" ";

        return (count1 + ((count2 > 0) ? count2 : 0));       
    }

    int solve(string &s, string& select, int x){
        int n = s.size();
        string intermediate = "";
        intermediate.push_back(s[0]);

        // int i = 0;
        int j = 1;

        while(j < n){
            if(!intermediate.empty() && intermediate.back() == select[0] && s[j] == select[1]){
                j++;
                intermediate.pop_back();
            }
            else{
                intermediate.push_back(s[j]);
                j++;
            }
        }

        int ans = (n - intermediate.size())/2 * x;
        s = intermediate;
        return ans;
    }
};