class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> st;

        int n = logs.size();
        int i=0;

        while(i<n){
            if(logs[i][0] == '.'){
                if(logs[i][1] == '.' && !st.empty())
                    st.pop();
            }
            else{
                st.push(1);
            }
            i++;
        }

        return st.size();
    }
};