class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // string to string conversion -> BFS Problem
        unordered_set<string> mp;
        for(auto s : bank){
            mp.insert(s);
        }

        unordered_set<string> visited;
        queue<string> q;
        q.push(startGene);

        visited.insert(startGene);

        int level = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                string currString = q.front();

                q.pop();
                if(currString == endGene) return level;

                for(char ch : "ACGT"){
                    for(int i=0; i<currString.size(); i++){
                        string s = currString;
                        s[i] = ch;
                        
                        if(visited.count(s) == 0 && mp.count(s)){
                            q.push(s);
                            visited.insert(s);
                        }
                    }
                }

            }

            level++;

        }

        return -1;

    }
};