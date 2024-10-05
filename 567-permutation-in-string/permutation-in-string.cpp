class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int k = s1.size();

        int i = 0;
        int j = 0;
        unordered_map<char, int> mp;

        for(int i=0; i<k; i++){
            mp[s1[i]]++;
        }

        int cnt = mp.size();

        while(j < n){

            if(mp.count(s2[j])){
                mp[s2[j]]--;
                if(mp[s2[j]] == 0){
                    cnt--;
                }
            }

            if(j-i+1 == k){
                if(cnt == 0){
                    return true;
                }
                if(mp.count(s2[i])){
                    mp[s2[i]]++;
                    if(mp[s2[i]] == 1){
                        cnt++;
                    }
                }
                i++;
            }

            j++;

        }

        return false;

    }
};