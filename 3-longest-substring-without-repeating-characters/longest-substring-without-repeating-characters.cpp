class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.size();
        int max_length = 0;
        
        for(int i =0; i<n; i++){

            map<int,int> mpp;
            int cnt  =0;

            for(int j = i; j<n; j++){
                if(mpp.find(s[j]) == mpp.end()){
                    cnt++;
                    mpp[s[j]]++;
                }
                else{
                    if(cnt > max_length){
                        max_length = cnt;
                    }
                    break;
                }
                max_length = max(max_length ,cnt);
            }
        }
        // if(max_length)
        return max_length;
    }
};