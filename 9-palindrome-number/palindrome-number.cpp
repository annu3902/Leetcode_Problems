class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        int temp = x;
        int ans=0;

        while(temp){
            int ld = temp % 10;
            if(ans > INT_MAX/10) return false;
            ans = ans*10 + ld;
            temp = temp/10;
        }

        return x == ans;
    }
};