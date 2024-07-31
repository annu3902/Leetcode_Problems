class Solution {
public:
    int minHeight(int i,vector<vector<int>> &books,int remWidth,int shelf, int height,vector<vector<int>> &dp){
        if (i==books.size()) return height;
        if (dp[i][remWidth]!=-1) return dp[i][remWidth];
        int currWidth=books[i][0];
        int currHeight=books[i][1];
        int pick=INT_MAX;
        if (remWidth>=currWidth){
            pick=minHeight(i+1,books,remWidth-currWidth,shelf,max(height,currHeight),dp);
        }
        int notpick=height+minHeight(i+1,books,shelf-currWidth,shelf,currHeight,dp);
        return dp[i][remWidth]=min(pick,notpick);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<vector<int>> dp(n,vector<int>(shelfWidth+1,-1));
        return minHeight(0,books,shelfWidth,shelfWidth,0,dp);
    }
};