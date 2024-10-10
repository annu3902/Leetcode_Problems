class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        stack<char> st;
        string str = "";

        // 1. Remove the balanced string
        for(int i=0; i<n; i++){
            if(s[i] == '['){
                st.push(s[i]);
            }

            else if(!st.empty()){
                st.pop();
            }

            else{
                str += s[i];
            }
        }

        int m = str.size();

        if((m & 1 )== 0){
            return m/2;
        }

        return m/2 + 1;

    }
};