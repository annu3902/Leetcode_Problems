class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else if(!st.empty()){
                char sh = st.top();
                if(sh == '(' && ch == ')'){
                    st.pop();
                }
                else if(sh == '{' && ch == '}'){
                    st.pop();
                }
                else if(sh == '[' && ch == ']'){
                    st.pop();
                }
                else{
                    return false;
                }
                continue;
            }   
            else{
                return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};