class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        int decision = (x >= y) ? 1 : 0;

        stack<int> st;
        
        int count1 = solve(decision, s, x, y);
        int count2 = solve(1-decision, s, x, y);

        return count1 + count2;

    }

    int solve(int decision, string& s, int x, int y){
        int n = s.size();
        int ans = 0;

        stack<char> st;
        int i = 0;
        // decision = 1 ->"ab";
        // decision = 0 ->"ba";

        while(i < s.size()){
            if(!st.empty() && st.top() == 'a' && decision == 1 && s[i]=='b'){ 
                st.pop();
                ans += x;
                i++;
                continue;
            }

            else if(!st.empty() && st.top() == 'b' && decision == 0 && s[i]=='a'){
                st.pop();
                ans += y;
                i++;
                continue;
            }

            st.push(s[i]);
            i++;
        }

        s.clear();
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }

        reverse(begin(s), end(s));

        return ans;
    }
};