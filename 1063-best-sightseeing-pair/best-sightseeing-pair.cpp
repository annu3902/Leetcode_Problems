class Solution {
public:

    int maxScoreSightseeingPair(vector<int>& values) {
      int n=values.size();
      int j=1;
      int maxi=values[0];
      int maxAns=0;
      while(j<n){
        maxAns=max(maxAns,maxi+values[j]-j);
        maxi=max(maxi,values[j]+j);
        j++;
      }
      return maxAns;
    }
};