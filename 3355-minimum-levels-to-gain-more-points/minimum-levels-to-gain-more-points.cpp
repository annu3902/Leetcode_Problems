class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=possible.size();
        for(int &num : possible){
            num = (num==1) ? 1 : -1;
        }
        int P2Points = accumulate(possible.begin(), possible.end(),0);
        int P1Points = 0;
        for(int i=0; i<n-1; i++){
            P1Points += possible[i];
            P2Points -= possible[i];
            if(P1Points > P2Points) return i+1;
        }
        return -1;
    }
};