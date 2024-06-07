class Solution {
public:
    // Implementing the trie data structure
    class trieNode{
        public :
        trieNode *children[26];
        bool isEnd;

        trieNode(){
            this->isEnd = false;

            for(int i=0; i<26; i++){
                this->children[i] = NULL;
            }
        }
    };

    /*trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;

        for(int i=0; i<26; i++){
            newNode->children[i] = NULL;
        }

        return trieNode;
    }*/

    trieNode* root;

    void insert(string word){
        trieNode* crawler = root;

        for(int i=0; i<word.size(); i++){
            int index = word[i] - 'a';
            if(crawler->children[index] == NULL){
                crawler->children[index] = new trieNode();
            }
            crawler = crawler->children[index];
        }

        crawler->isEnd = true;
    }

    string search(string word){
        trieNode* crawler = root;

        for(int i=0; i<word.size(); i++){
            int index = word[i] - 'a';
            if(crawler->children[index] == NULL){
                // the root of this word is not present 
                return word;
            }
            
            crawler = crawler->children[index];
            if(crawler->isEnd == true){
                return word.substr(0, i+1);
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new trieNode();

        for(string &word : dictionary){
            insert(word);
        }

        stringstream ss(sentence);
        string word;

        string result="";

        while(ss >> word){
            result += search(word) +" ";
        }

        result.pop_back();
        return result;
    }
};