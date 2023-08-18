class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n =s.size();
        unordered_map<char,int> mpp;
        list<int> ls;
        int max_length = 0;
        int cnt = 0;

        for(int i =0; i<n; i++){

            if(mpp.find(s[i]) == mpp.end()){
                cnt++;
                ls.push_back(s[i]);
                mpp[s[i]]++;
            }

            else{
                max_length = max(max_length, cnt);

                while(ls.front() != s[i]){
                    mpp.erase(ls.front());
                    ls.pop_front();
                    cnt--;
                }

                mpp.erase(ls.front());
                ls.pop_front();
                cnt--;

                mpp[s[i]]++;
                ls.push_back(s[i]);
                cnt++;
                
            }
        }
        max_length = max(max_length, cnt);
        return max_length;

    }
};