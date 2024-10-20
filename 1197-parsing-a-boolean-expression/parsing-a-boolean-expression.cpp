class Solution {
public:
    char solve(vector<char> &s, char op){
        if(op == '!')
            return s[0] == 't'? 'f' : 't';

        if(op == '&'){
            for(int i=0; i<s.size(); i++){
                if(s[i] == 'f')
                    return 'f';
            }
            return 't';
        }
        if(op == '|'){
            for(int i=0; i<s.size(); i++){
                if(s[i] == 't')
                    return 't';
            }
            return 'f';
        }
        return 't';
    }
    bool parseBoolExpr(string s) {
        
        int n = s.size();
        stack<char> st;

        for(int i=0; i<n; i++){
            //if comma appear
            if(s[i] == ','){
                continue;
            }
            // if close bracket appear
            else if(s[i] == ')'){
                //to store the inner charactor
                vector<char> store;
                //removing all the t & f charactor
                while(st.top() != '('){
                    store.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                st.push(solve(store, op));
            }
            //insert all the characator in it.
            else{
                st.push(s[i]);
            }
        }
        return st.top() == 't'? true: false;
    }
};