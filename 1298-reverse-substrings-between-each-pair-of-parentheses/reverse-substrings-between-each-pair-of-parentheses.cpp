class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;  // to store the length of the string in the answer to be reversed

        string result="";

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(result.size());
            }

            else if(s[i] == ')'){
                int length = st.top();
                st.pop();
                reverse(result.begin() + length, result.end());
            }

            else{
                result.push_back(s[i]);
            }
        }

        return result;


    }
};