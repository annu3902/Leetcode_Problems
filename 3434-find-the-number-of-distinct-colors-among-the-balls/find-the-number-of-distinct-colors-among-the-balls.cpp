class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> colors;
        map<int, int> mpp;
        vector<int> ans;
        
        for(vector<int> vec : queries){
            
            int ball = vec[0];
            int color = vec[1];
            
            
            if(mpp.find(ball) != mpp.end()){
                int prevColor = mpp[ball];
                
                colors[prevColor]--;
                if(colors[prevColor] == 0){
                    colors.erase(prevColor);
                }
            }
            
    
                mpp[ball] = color;
                colors[color]++;    
            
            
            
            int stSize = colors.size();
            ans.push_back(stSize);            
        }
        return ans;
    }
};
