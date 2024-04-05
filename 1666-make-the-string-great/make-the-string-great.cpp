class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        if(n==0) return s;
        string ans;
        stack<char> st;
        int i=0;

        while(i<n){
            if(!st.empty() && (s[i]-'A'+'a' == st.top() || s[i]-'a'+'A' == st.top())){
                st.pop();
            }
            else
                st.push(s[i]);
            i++;
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};