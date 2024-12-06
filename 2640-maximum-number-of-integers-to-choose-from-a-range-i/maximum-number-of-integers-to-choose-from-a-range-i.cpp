class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum)
    {
        int used = 0;
        int sum = 0;
        vector<int> mask(n + 1, 0);
        for(const auto& b : banned) {
            if(b <= n) {
                mask[b] = 1;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(!mask[i] && sum + i <= maxSum) {
                used += 1;
                sum += i;
            }
            else if (sum + i > maxSum) {
                break;
            }
        }
        return used;
    }
};