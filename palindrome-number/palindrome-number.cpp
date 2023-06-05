class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long int sum =0;
        if(temp<0) return false;
        else {
                while(temp!=0){
                int y = temp%10;
                sum = sum*10+y;
                temp=temp/10;
            }
            if(sum == x) return true;
            else return false;
        }
    }
};