class Solution {
public:
    int countVowelSubstrings(string nums) {
        int n = nums.size();
        int cnt = 0;

        for(int i=0; i<n; i++){
            unordered_map<char, int> mp;

            for(int j=i; j<n && isVowel(nums[j]); j++){ // THis loop is to count kha tak ham substring bana skte h
                mp[nums[j]]++;
                if(mp.size() == 5) cnt++;
            }
        }
        return cnt;
    }

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};