class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;

        int time = customers[0][0];
        double sum = 0;

        for(vector<int> costumer : customers){
            if(costumer[0] <= time){
                time += costumer[1]; 
                int wait = time - costumer[0];
                sum += wait;
            }
            else{
                time = costumer[0];
                time += costumer[1];
                int wait = time - costumer[0];
                sum += wait;
            }
        }

        return sum/customers.size();     
    }
};