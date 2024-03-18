class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // atmost 2 people in a boat
        // can accomodate 2 people in a boat with a maxLimit in a single boat
        int n=people.size();
        sort(people.begin(), people.end());
        int No_of_Boats=0;
        int remaining=limit;
        int No_of_People=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            if(people[j]+people[i]<=limit){
                No_of_Boats++;
                i++;
                j--;
            }
            else{
                No_of_Boats++;
                j--;
            }
        }   
        return No_of_Boats;
    }
};