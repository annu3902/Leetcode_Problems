class Solution {
public:
    int countVowelSubstrings(string word) {
        return (atMost(word, 5) - atMost(word, 4));
    }

    int atMost(string nums, int k){

        int n = nums.size();
        int i=0;
        int j=0;
        int cnt = 0;
        unordered_map<char, int> mp;

        while(j < n){
            if(isVowel(nums[j])){
                mp[nums[j]] ++;

                while(mp.size() > k){
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }

                if(mp.size() <= k)
                    cnt += (j-i+1);
            }

            else{
                mp.clear();
                i = j+1;
            }

            j++;
        }
        cout<<cnt<<" ";

        return cnt;

    }

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
    }
};