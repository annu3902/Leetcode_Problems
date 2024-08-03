class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();

        // vector<vector<int>> dp(n, vector<int>(selfWidth, -1));
        vector<vector<int>> dp(n, vector<int> (shelfWidth + 1, -1));
        return dfs(0, shelfWidth, shelfWidth, 0, books, dp);
    }

    int dfs(int index, int remWidth, int selfWidth, int maxHeight, vector<vector<int>>& books, vector<vector<int>>& dp){
        if(index >= books.size()){
            return maxHeight;
        }

        if(dp[index][remWidth] != -1) return dp[index][remWidth];

        int bookWidth = books[index][0];
        int bookHeight = books[index][1];

        int place = 1e9;
        if(bookWidth <= remWidth){
            place = dfs(index + 1, remWidth - bookWidth, selfWidth, max(maxHeight, bookHeight), books, dp);
        }

        int notPlace = maxHeight + dfs(index+1, selfWidth - bookWidth, selfWidth, bookHeight, books, dp);

        return dp[index][remWidth] = min(place , notPlace);
    }
};