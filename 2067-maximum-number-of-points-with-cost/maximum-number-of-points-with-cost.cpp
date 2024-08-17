typedef long long ll;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
    
        vector<vector<ll>> cache(n, vector<ll>(m, INT_MIN));
    
        for (int i = n - 1; i >= 0; i--) {
            if ((i + 1) < n) {
                priority_queue<pair<ll, int>> left_q, right_q;
                
                for (int j = 0; j < m; j++) {
                    right_q.emplace(cache[i + 1][j] - j, j);
                }

                auto right_top = right_q.top();
                cache[i][0] = points[i][0] + right_top.first;

                for (int j = 1; j < m; j++) {
                    while (right_top.second < j) {
                        right_q.pop();
                        right_top = right_q.top();
                    }

                    left_q.emplace(cache[i + 1][j - 1] - abs(m - j), j - 1);
                    auto left_top = left_q.top();

                    ll right_score = cache[i + 1][right_top.second] - abs(j - right_top.second);
                    ll left_score = cache[i + 1][left_top.second] - abs(j - left_top.second);

                    cache[i][j] = points[i][j] + max(left_score, right_score);
                }
            }                       
            else {
                for (int j = 0; j < m; j++) {
                    cache[i][j] = points[i][j];
                }
            } 
        }

        ll max_score = INT_MIN;
    
        for (int i = 0; i < m; i++) {
            max_score = max(max_score, cache[0][i]);
        }

        return max_score;
    }
};