class Solution {
public:

    long countStepsInSubtree(long n, long current, long next) {
        long result = 0;
        while (current <= n) {
            result += std::min(n + 1, next) - current;
            current *= 10;
            next *= 10;
        }
        return result;
    }

    long findKthNumber(long n, long k) {
        long current = 1;
        k--;
        while (k > 0) {
            long steps = countStepsInSubtree(n, current, current + 1);
            if (steps <= k) {
                k -= steps;
                current++;
            } else {
                k--;
                current *= 10;
            }
        }
        return current;
    }
};