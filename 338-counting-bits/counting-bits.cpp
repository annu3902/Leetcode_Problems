class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int num = 0; num<=n; num++){
            int count = 0;
            for(int j=0; j<32; j++){
                if((num & (1<<j)) != 0) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};