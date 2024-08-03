class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        int n = books.size();

        // vector<vector<int>> dp(n, vector<int>(selfWidth, -1));
        vector<vector<int>> dp(n, vector<int> (shelfWidth + 1, -1));

        return dfs(n-1, shelfWidth, shelfWidth, 0, books, dp);        

        /*for(int i=n-1; i>=0; i++){
            for(int remWidth = 0; remWidth <= shelfWidth; remWidth++){
                int bookWidth = books[i][0];
                int bookHeight = books[i][1];

                int place = 1e9;
                if(bookWidth <= remWidth){
                    place = dp[][]
                }

            }
        }*/
        
    }

    /*int dfs(int index, int remWidth, int selfWidth, int maxHeight, vector<vector<int>>& books, vector<vector<int>>& dp){
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
    }*/

    int dfs(int index, int remWidth, int shelfWidth, int maxHeight, vector<vector<int>>& books, vector<vector<int>>& dp){
            if(index < 0){
                return maxHeight;
            }

            if(dp[index][remWidth] != -1) return dp[index][remWidth];

            int bookWidth = books[index][0];
            int bookHeight = books[index][1];

            int pick = 1e9;
            if(bookWidth <= remWidth){
                pick = dfs(index-1, remWidth - bookWidth, shelfWidth, max(maxHeight, bookHeight), books, dp);
            }

            int notPick = maxHeight + dfs(index-1, shelfWidth - bookWidth, shelfWidth, bookHeight, books, dp);     

            return dp[index][remWidth] = min(pick, notPick);
    }
};