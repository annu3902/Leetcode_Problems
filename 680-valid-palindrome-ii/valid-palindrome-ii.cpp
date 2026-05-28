class Solution {
public:
    bool palindromeCheck(int left, int right, string s){
        int n=s.size();
        
        while(left<=right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();

        int left = 0;
        int right = n-1;
        bool flag = false;

        while(left <= right){
            if(s[left] != s[right] && flag == false){
                if(palindromeCheck(left + 1, right, s) == true || palindromeCheck(left, right-1, s) == true){
                    flag = true;
                    return true;
                }
                else return false;
            }
            left++;
            right--;
        }

        return true;
    }
};