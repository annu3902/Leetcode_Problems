class Solution {
public:
    string reverseParentheses(string s) {
        string result;
        unordered_map<int, int> mp;
        bool direction = 0; //  0 means LTR
                            // 1 means RTL
        stack<int> st;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }   

            else if(s[i] == ')'){
                int startIdx = st.top();
                st.pop();
                mp[startIdx] = i;
                mp[i] = startIdx;
            }

            else continue;
        }


        // for(auto it : mp){
        //     cout<<it.first<<" "<<it.second<<" "<<endl;
        // }

        int i = 0;
        while(i >= 0 && i < s.size()){
            if(s[i] == '(' || s[i] == ')'){
                int x = mp[i];
                i = x;
                direction = 1 - direction;
                if(direction == 0){
                    i++;
                }
                else{
                    i--;
                }
            }

            else{
                if(direction == 0){
                    result.push_back(s[i]);
                    i++;
                }
                else{
                    result.push_back(s[i]);
                    i--;
                }
            }
        }

        return result;

    }
};