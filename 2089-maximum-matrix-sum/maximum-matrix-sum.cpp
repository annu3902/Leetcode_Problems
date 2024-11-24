class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        long long sum = 0;
        int min_abs = INT_MAX;
        int neg_count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = matrix[i][j];
                sum += abs(x);
                min_abs = min(abs(x), min_abs);

                if (x < 0)
                    neg_count++;
            }
        }

        return (sum - ((neg_count % 2) ? min_abs * 2 : 0));
    }
};