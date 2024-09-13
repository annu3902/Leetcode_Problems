class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;

        unordered_map<char, int> mp;
        for(int i=0; i<allowed.size(); i++){
            mp[allowed[i]]++;
        }

        for(auto st : words){

            bool flag = true;
            for(auto c : st){
                if(mp.count(c) == 0){
                    flag = false;
                    continue;
                } 
            }

            if(flag) count++;
        }

        return count;
    }
};