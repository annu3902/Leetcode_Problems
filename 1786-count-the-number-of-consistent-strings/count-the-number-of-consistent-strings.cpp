class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
         unordered_set<char> set(allowed.begin(),allowed.end());
         int count=0;

         for(auto& word:words){
            bool isConsistent=true;

            for(auto& ch:word){
                if(set.find(ch)==set.end()){
                    isConsistent=false;
                    break;
                }
            }
            if(isConsistent){
                count++;
            }
         }
        return count;
    }
};