class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        for(int i=0; i<n; i++){
            if(i>=1 && s[i]=='0'){
                swap(s[i-1], s[n-1]);
                break;
            }
        }
        return s;
    }
};