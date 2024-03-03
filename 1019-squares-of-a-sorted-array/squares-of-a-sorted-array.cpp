class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>squares;
        for(int x : nums){
            squares.push_back(x*x);
        }
        sort(squares.begin(), squares.end());
        return squares;
    }
};