class Solution {
public:
    string shortestPalindrome(string s) {

        // KMP START
        string temp=s+'?';
        reverse(s.begin(),s.end());
        temp+=s;
        reverse(s.begin(),s.end());
        int n=temp.length();
        vector<int> lps(n,0);
        for(int i=1;i<n;i++){
            int l=lps[i-1];
            while(l>0 && temp[l]!=temp[i]) l=lps[l-1];
            if(temp[i]==temp[l]) l++;
            lps[i]=l;
        }
        // KMP END
        int p=lps[n-1];
        string prefix=s.substr(p,s.length());
        reverse(prefix.begin(),prefix.end());
        return prefix+s;
    }
};