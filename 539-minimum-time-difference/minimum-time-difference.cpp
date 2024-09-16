class Solution {
public:
    int minutesInDay = 1440;
    int findMinDifference(vector<string>& timePoints) {
        vector<int> timePresent(minutesInDay, 0); // Array to mark time points
        int numTimes = timePoints.size();
        
        // Convert each time point to minutes and mark it
        for (int i = 0; i < numTimes; i++) {
            int hours = 10 * (timePoints[i][0] - '0') + (timePoints[i][1] - '0');
            int minutes = 10 * (timePoints[i][3] - '0') + (timePoints[i][4] - '0');
            int minuteValue = hours * 60 + minutes;
            
            // If the time is already marked, return 0 (minimum possible difference)
            if (timePresent[minuteValue]) return 0;
            timePresent[minuteValue]++;
        }
        
        int minimumDifference = INT_MAX; // Initialize to a large value

        // Find the minimum difference
        for (int minuteValue = 0; minuteValue < minutesInDay; minuteValue++) {
            if (timePresent[minuteValue]) {
                int distance = 1;
                while (distance < minutesInDay) {
                    int earlierMinute = ((minuteValue - distance) % minutesInDay + minutesInDay) % minutesInDay;
                    int laterMinute = (minuteValue + distance) % minutesInDay;

                    if (timePresent[earlierMinute] || timePresent[laterMinute]) {
                        minimumDifference = min(minimumDifference, distance);
                        break; // No need to check further since we found the nearest point
                    }
                    distance++;
                }
            }
        }
        
        return minimumDifference;
    }
};