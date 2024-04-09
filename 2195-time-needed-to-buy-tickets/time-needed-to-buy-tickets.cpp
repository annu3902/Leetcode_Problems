// OJ: https://leetcode.com/problems/time-needed-to-buy-tickets/
// Author: github.com/lzl124631x
// Time: O(SUM(A))
// Space: O(1)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& A, int k) {
        int step = 0;
        while (true) {
            for (int i = 0; i < A.size(); ++i) {
                if (A[i] == 0) continue;
                A[i]--;
                ++step;
                if (A[k] == 0) return step;
            }
        }
    }
};