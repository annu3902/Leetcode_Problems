class Solution {
public:


    int findJudge(int n, vector<vector<int>>& trust) {
        // int n=trust.size();
        map<int, vector<int>> mpp;

        for(vector<int> x:trust){
            int first = x[0];
            int second = x[1];
            mpp[first].push_back(second);
        }

        // for(auto it : mpp){
        //     int x = it.first;
        //     vector<int> temp = it.second;
        //     if(temp.empty()) return x;
        //     else{
        //         cnt++;
        //     }
        // }

        for(int i=1; i<=n; ++i){
            if(mpp.count(i)) continue;
            else{
                int cnt=0;  
                for(auto it : mpp){
                    int x =it.first;
                    vector<int> y = it.second;
                    sort(y.begin(), y.end());
                    if(binary_search(y.begin(), y.end(), i)){
                        cnt++;
                    }
                }
                if(cnt==n-1) return i;
            }
        }
        return -1;
    }
};