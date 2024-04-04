class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int cnt=0;
        stack<int> st;
        int n=s.size();
        int i=0;
        while(i<n){
            if(s[i]=='('){
                st.push(s[i]);
                cnt++;
                maxi = max(maxi, cnt);
            }
            else if(s[i]==')'){
                st.pop();
                cnt--;
            }
            i++;
        }
        return maxi;
    }
};