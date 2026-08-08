class Solution {
public:
    bool isReachIsPossible(vector<int>& dist, long minSpeed, double hour){
        int n = dist.size();
        double totalTimeNeeded = 0;

        for(int i=0; i<n; i++){
            if(i != n-1){ totalTimeNeeded += ceil((double)dist[i]/minSpeed);}
            else{
                double timeNeeded = (double)dist[i]/minSpeed;
                totalTimeNeeded += timeNeeded;
            }
            // totalTimeNeeded += ceil(dist[i] / minSpeed);

        }

        if(totalTimeNeeded <= hour) return true;
        return false;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        long left = 1;
        long right = 1e7;
        long ans = -1;

        while(left <= right){
            long mid = left + (right - left)/2;
            if(isReachIsPossible(dist, mid, hour)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return ans;
    }
};