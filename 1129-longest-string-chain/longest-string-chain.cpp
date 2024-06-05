class Solution {
public:
    vector<string> customSort(vector<string>& words){
        vector<string> result;

        vector<vector<string>> vec (17);
        for(int i=0; i<words.size(); i++){
            vec[words[i].size()].push_back(words[i]);            
        }

        for(vector<string> &word : vec){
            if(word.size() == 0) continue;

            for(auto &names : word){
                result.push_back(names);
            }
        }

        return result;
    }

    int longestStrChain(vector<string>& words) {
        words = customSort(words);

        int n = words.size();

        vector<int> dp(n, 1);
        // dp[i] -> Length of LIS ending at i;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                
                if(words[i].size()-words[j].size() == 1){
                    int left = 0;
                    int right = 0;
                    bool flag = 0;

                    while(left < words[j].size() && right < words[i].size()){

                        if(words[j][left] != words[i][right]){
                            if(flag == false){
                                right++;
                                flag = true;
                            }
                            else{
                                break;
                            }
                        }
                        else{
                            left++;
                            right++;
                        }

                    }

                    if(left == words[j].size()){
                        dp[i] = max(dp[i], 1 + dp[j]);
                    }
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};