// class Solution {
// public:
//     int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

//         int n = books.size();
//         vector<vector<int>> dp(n, vector<int> (shelfWidth + 1, -1));

//         return dfs(n-1, shelfWidth, shelfWidth, 0, books, dp);        
//     }

//     int dfs(int index, int remWidth, int shelfWidth, int maxHeight, vector<vector<int>>& books, vector<vector<int>>& dp){
//             if(index < 0){
//                 return maxHeight;
//             }

//             if(dp[index][remWidth] != -1) return dp[index][remWidth];

//             int bookWidth = books[index][0];
//             int bookHeight = books[index][1];

//             int pick = 1e9;
//             if(bookWidth <= remWidth){
//                 pick = dfs(index-1, remWidth - bookWidth, shelfWidth, max(maxHeight, bookHeight), books, dp);
//             }

//             int notPick = maxHeight + dfs(index-1, shelfWidth - bookWidth, shelfWidth, bookHeight, books, dp);     

//             return dp[index][remWidth] = min(pick, notPick);
//     }
// };


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n, vector<int> (shelfWidth + 1, -1));
        return dfs(n-1, shelfWidth, shelfWidth, 0, books, dp);        
    }

    int dfs(int index, int remWidth, int shelfWidth, int maxHeight, vector<vector<int>>& books, vector<vector<int>>& dp) {
        if (index < 0) {
            return maxHeight;
        }

        if (dp[index][remWidth] != -1) {
            return dp[index][remWidth];
        }

        int bookWidth = books[index][0];
        int bookHeight = books[index][1];

        int pick = 1e9;
        if (bookWidth <= remWidth) {
            pick = dfs(index - 1, remWidth - bookWidth, shelfWidth, max(maxHeight, bookHeight), books, dp);
        }

        int notPick = maxHeight + dfs(index - 1, shelfWidth - bookWidth, shelfWidth, bookHeight, books, dp);     

        return dp[index][remWidth] = min(pick, notPick);
    }
};
