class Trie {
public:
    class TrieNode{
        public:
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            this->isEnd = false;
            for(int i=0; i<26; i++){
                this->children[i] = NULL;
            }  
        };
    };
    
    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* crawler = root;

        for(int i=0; i<word.size(); i++){
            int index = word[i] - 'a';
            if(crawler->children[index] == NULL){
                crawler->children[index] = new TrieNode();
            }
            crawler = crawler->children[index];
        }

        crawler->isEnd = true;

    }
    
    bool search(string word) {
        TrieNode* crawler = root;

        for(int i=0; i<word.size(); i++){
            int index = word[i] - 'a';
            if(crawler->children[index] == NULL) return false;

            crawler = crawler->children[index];
        }

        return crawler->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;

        for(int i=0; i<prefix.size(); i++){
            int index= prefix[i] - 'a';
            if(crawler->children[index] == NULL) return false;

            crawler = crawler->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */