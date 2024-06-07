class Solution {
public:
    class trieNode{
        public:
        trieNode* children[26];
        bool isEnd;

        trieNode(){
            this->isEnd = false;
            for(int i=0; i<26; i++){
                this->children[i] = NULL;
            }
        }
    };

    trieNode* root;

    void insert(string word){
        trieNode* crawler = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i] - 'a';

            if(crawler->children[index] == NULL){
                crawler->children[index] = new trieNode();
            }

            crawler = crawler->children[index];
        }
        crawler->isEnd = true;
    }

    bool search(int start, const string& word, vector<bool>& dp) {
        trieNode* crawler = root;
        for (int i = start; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (crawler->children[index] == NULL) return false;
            crawler = crawler->children[index];
            if (crawler->isEnd && dp[start]) {
                dp[i + 1] = true;
            }
        }
        return dp[word.size()];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        root = new trieNode();
        int n = s.size();

        // Insertion in trie
        for(string &word : wordDict){
            insert(word);
        }

        // dp[i] -> i length ka word can be segmented ?
        vector<bool> dp(n+1, 0);
        dp[0] = true;

        for(int i=0; i<n; i++){
            if(dp[i] == true){
                search(i, s, dp);
            }
        }
        return dp[n];
    }
};