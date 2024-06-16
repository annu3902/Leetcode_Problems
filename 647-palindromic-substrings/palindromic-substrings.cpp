class Solution {
public:
    int count = 0;

    int countSubstrings(string s) {
        count = 0;

        int n = s.size();
        for(int i=0; i<n; i++){

            checkPalindrome(i, i, s, n);
            checkPalindrome(i, i+1, s, n);

        }

        return count;

    }

    void checkPalindrome(int i, int j, string& s, int n){

        if(i > j) return;

        while(i >= 0 && j < n && s[i] == s[j]){
            count++;
            i--;
            j++;
        }

        return;

    }
};