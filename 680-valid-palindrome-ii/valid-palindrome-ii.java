class Solution {
    public boolean checkPalindrome(int left, int right, String s){
        int n=s.length();

        while(left<=right){
            if(s.charAt(left) != s.charAt(right)) return false;
            left++;
            right--;
        }

        return true;
    }

    public boolean validPalindrome(String s) {
        int n = s.length();

        int left = 0;
        int right = n-1;
        boolean flag = false;

        while(left <= right){

            if(s.charAt(left) != s.charAt(right) && flag == false){
                flag = true;
                if(checkPalindrome(left + 1, right, s) == true || checkPalindrome(left, right - 1, s) == true){
                    return true;
                }

                else return false;
            }
            left++;
            right--;
        }

        return true;
    }
}