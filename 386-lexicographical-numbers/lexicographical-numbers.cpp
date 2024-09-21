class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int speed = []() {ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();

        vector<int> sol(n);
        int idx = 0;
        int cur = 1;
        while (idx < n) {
            // if cur is in range take it 
            if (cur <= n) sol[idx++] = cur;

            // if it's possible to dive deeper into lexi numbers
            // e.g 101 -> 1010
            if (cur*10 <= n) cur *= 10;
            else {
                cur += 1;
                // get to the origin where we have to proceed

                // e.g last cur += 1: 10019 -> 10020
                // now we have to make step: 10020 -> 1002
                while (cur % 10 == 0) cur /= 10;
            }
        }
       return sol; 
    }
};