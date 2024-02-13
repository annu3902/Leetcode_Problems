class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n =words.size();

        for(string s : words){
            int left = 0;
            int right = s.size()-1;
            while(left < right){
                if(s[left] != s[right]){
                    break;
                }
                else{
                    left++;
                    right--;
                }
            }
            if(left >= right){
                return s;
            }
        }
        return "";
    }
};