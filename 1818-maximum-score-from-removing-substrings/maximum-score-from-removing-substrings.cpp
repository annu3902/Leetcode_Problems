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

        return (count1 + count2);     
    }

    int solve(string &s, string& select, int x){
        int n = s.size();
        
        int i=0; int j=0;
        while(j < n){

            s[i] = s[j];
            i++;
            if(i-2>=0 && s[i-2] == select[0] && s[i-1] == select[1]){
                i -= 2;
            }

            j++;

        }
        s.erase(s.begin()+i, s.end());

        int ans = (n - i)/2 * x;
        return ans;
    }
};