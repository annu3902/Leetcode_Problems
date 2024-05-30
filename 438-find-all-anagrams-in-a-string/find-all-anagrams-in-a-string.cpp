class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;


        // Dictionary creation
        int n = p.size();
        unordered_map<int, int> mpp;
        for(char &ch : p){
            mpp[ch]++;
        }

        int count = mpp.size();
        int i=0; // staring point of window
        int j=0;   // ending point pf window

        while(j < s.size()){

            if(mpp.count(s[j])){
                mpp[s[j]]--;

                if(mpp[s[j]] == 0){
                    count--;
                }
            }

            int length = j-i+1;
            if(length < n){
                j++;
                continue;
            }

            else if(length == n){

                if(count == 0) ans.push_back(i);

                if(mpp.count(s[i])){
                    if(mpp[s[i]] == 0) count++;

                    mpp[s[i]]++;
                }
                i++; // sliding the wingdow
                j++;

            }

        }
        return ans;
    }
};