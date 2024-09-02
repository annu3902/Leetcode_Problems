class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long n = chalk.size();
        // Use long long for the sum to avoid overflow
        long long s = accumulate(chalk.begin(), chalk.end(), 0LL); // Notice the 0LL to specify long long
        int m = k % s;  // 'm' can remain an int since its value will be less than 's'
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (m - chalk[i] < 0) {
                ans = i;
                break;
            } else {
                m -= chalk[i]; // Subtract chalk[i] from m
            }
        }
        return ans;
    }
};