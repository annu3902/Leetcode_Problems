class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        // Keep the count of left and right braces from left and right

        int left=0;
        int right=0;
        int maxLength = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                left++;
            }
            else if(s[i] == ')'){
                right++;
            }

            if(left == right){
                int length = 2*left;
                maxLength = max(maxLength, length);
            }

            else if(right > left){
                right = 0;
                left = 0;
            }
        }

        left = 0;
        right = 0;

        for(int i=n-1; i>=0; i--){

            if(s[i] == ')') right++;

            else if(s[i] == '(') left++;

            if(left == right) maxLength = max(maxLength, 2*right);

            else if(left > right){
                left = 0;
                right = 0;
            }

        }

        return maxLength;

    }
};