class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> actualOrder = heights;
        sort(begin(actualOrder), end(actualOrder));

        int count = 0;
        for(int i=0; i < n; i++){
            if(heights[i] != actualOrder[i]) count++;
        }

        return count;

    }
};