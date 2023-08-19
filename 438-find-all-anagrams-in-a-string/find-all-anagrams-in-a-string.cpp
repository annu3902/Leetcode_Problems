class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        int start = 0;
        int end = 0;
        unordered_map<char,int> mpp;
        vector<int> ans;

        for(int i =0; i<k; i++){
            mpp[p[i]]++;
        }

        int distinct_cnt = mpp.size();

        while(end < n){
            if(mpp.find(s[end]) != mpp.end()){
                mpp[s[end]]--;
                if(mpp[s[end]] == 0){
                    distinct_cnt--;
                }
            }

            if(end - start +1 < k){
                end++;
            }

            else if(end - start + 1 == k){
                cout<<distinct_cnt<<" ";
                if(distinct_cnt == 0){
                    ans.push_back(start);
                    cout<<start<<" ";
                }

                // Backtracking
                if(mpp.find(s[start]) != mpp.end()){
                    mpp[s[start]]++;
                    if(mpp[s[start]] == 1){
                        distinct_cnt++;
                    }
                }

                // Slide the Window
                start++;
                end++;
            }
        }
        return ans;
    }
};