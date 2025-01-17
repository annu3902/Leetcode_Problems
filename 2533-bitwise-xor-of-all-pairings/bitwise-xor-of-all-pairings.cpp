class Solution {
public:
    int xorAllNums(vector<int>& n1, vector<int>& n2) {
        int ans = 0;
        if(n2.size() % 2 != 0) 
            for(auto i : n1)
                ans = ans ^ i;
        if(n1.size() % 2 != 0) 
            for(auto i : n2)
                ans = ans ^ i;
        return ans;
    }
};