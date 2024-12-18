class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> incrSt{{prices.back()}};
        vector<int> res{prices.back()};
        for (int i = prices.size() - 2; i >= 0; --i) {
            while (incrSt.size() && prices[i] < incrSt.top()) {
                incrSt.pop();
            }
            if (incrSt.size()) {
                res.push_back(prices[i] - incrSt.top());
            } else {
                res.push_back(prices[i]);
            }

            if (incrSt.empty() || prices[i] != incrSt.top())
                incrSt.push(prices[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};