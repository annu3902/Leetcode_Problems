class Solution {
public:
   
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();
        map<int,int> m;
     for(int i=0;i<n;i++)
     {
       int j=0;
       while(candidates[i]>0)
       {
        if(candidates[i]&1==1)
        m[j]++;
        j++;
        candidates[i]>>=1;
       }
     }
     int max=0;
     for(auto p:m)
     {
        if(p.second>max)
        max=p.second;
     }
     return max;
    }
};