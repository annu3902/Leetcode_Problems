class Solution {
private:
    string expand(int l, int r, string& s){
        int start = l;
        int length = 1;
        
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            start = l;
            length = r - l + 1;
            l--;
            r++;
        }

        return s.substr(start, length);
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans="";

        for(int i=0; i<n; i++){
            string odd = expand(i, i, s);

            string even = expand(i, i+1, s);

            if(odd.size() > ans.size()){
                ans = odd;
            }

            if(even.size() > ans.size()){
                ans = even;
            }
        }

        return ans;
    }
};