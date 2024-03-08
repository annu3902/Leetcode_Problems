class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        for(int x: nums){
            mpp[x]++;
        }

        int maxCnt=0;
        int cnt=0;
        for(pair<int,int> x: mpp){
            if(cnt==x.second){
                maxCnt+=cnt;
            }
            else if(cnt<x.second){
                cnt=x.second;
                maxCnt=cnt;
            }
        }
        return maxCnt;
    }
};