class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;

        for(int i=0; i<s.size(); i++){
            if(!st1.empty() && s[i] == '#')
            {
                st1.pop();
                continue;
            }
            else if(st1.empty() && s[i] == '#'){
                continue;
            }

            st1.push(s[i]);
        }

        for(int i=0; i<t.size(); i++){
            if(!st2.empty() && t[i] == '#')
            {
                st2.pop();
                continue;
            }
            else if(st2.empty() && t[i] == '#'){
                continue;
            }

            st2.push(t[i]);
        }

        if(st1.size() != st2.size()) return false;

        while(!st1.empty() && !st2.empty()){
            auto it1 = st1.top();
            auto it2 = st2.top();
            if((it1) != (it2)){
                return false;
            }
            st1.pop();
            st2.pop();
        }

        return true;
    }
};