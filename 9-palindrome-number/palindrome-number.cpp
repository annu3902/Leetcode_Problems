class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long rev_num = 0;

        while(temp > 0){
            int ld = temp % 10;
            temp = temp/10;
            rev_num = (rev_num * 10) + ld;
        }

        if(rev_num == x) return true;
        return false;
    }
};