class Solution {
public:
    int minLength(string s) {
        // Implement stack
        stack<char> stk; stk.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            bool flag = false;
            // Get top element
            if (!stk.empty()) {
                char c = stk.top();
                // If substring found, remove top of stack
                if ((c == 'A' and s[i] == 'B') or (c == 'C' and s[i] == 'D')) {
                    stk.pop();
                    // Mark as removed
                    flag = true;
                }
            }
            // If not removed, add the char
            if (!flag) stk.push(s[i]);
        }
        // Return the stack size after all chars removed
        return stk.size();
    }
};