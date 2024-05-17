class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        // start ---> end
        unordered_set<string> bankSet(bank.begin(), bank.end()); // O(1) --> Access time
        unordered_set<string> visited;

        queue<string> q;
        q.push(start);
        visited.insert(start);
        int level=0;

        while(!q.empty()){

            int n=q.size();
            while(n--){

                string curr = q.front();
                q.pop();

                if(curr == end) return level;

                for(char ch : "ACGT"){
                    
                    for(int i=0; i<curr.size(); i++){
                        string neighbour = curr;
                        neighbour[i] = ch;

                        if(visited.find(neighbour) == visited.end() && bankSet.find(neighbour) != bankSet.end()){
                            q.push(neighbour);
                            visited.insert(neighbour);
                        }
                    }
                }

            }
            level++;
        }
    return -1;
    }
};