class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<pair<char,int>> st;

        int i=0;
        while(i<n){

            if(st.empty() && (s[i] == '(' || s[i] == ')')){
                st.push({s[i] , i});
            }

            else if(s[i] == '('){
                st.push({s[i], i});
            }
            
            else if(s[i] == ')' && st.top().first == '('){
                st.pop();
            }

            else if(s[i] == ')' && !st.empty()){
                st.push({s[i], i});
            }
            i++;
        }

        while(!st.empty()){
            s.erase(st.top().second , 1);
            st.pop();
        }
        return s;
    }
};