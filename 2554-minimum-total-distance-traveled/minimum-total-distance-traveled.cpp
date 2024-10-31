class Solution {
public:
    vector<vector<vector<long long>>> dp;

    long long helper(int i, int j, vector<int>& robot, vector<vector<int>>& factory){
        if(i >= robot.size()){
            return 0;
        }
        if(j >= factory.size()){
            return LLONG_MAX/10;
        }

        if(dp[i][j][factory[j][1]] != -1){
            return dp[i][j][factory[j][1]];
        }

        long long not_take = helper(i, j+1, robot, factory);

        long long take = LLONG_MAX;
        if(factory[j][1] > 0){
            factory[j][1]--;
            take = abs(factory[j][0] - robot[i]) + helper(i+1, j, robot, factory);
            factory[j][1]++;
        }

        return dp[i][j][factory[j][1]] = min(not_take, take);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        dp.resize(robot.size()+2, vector<vector<long long>>(factory.size()+2, vector<long long>(robot.size()+2, -1)));

        return helper(0, 0, robot, factory);
    }
};