class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        //if(quantities.empty()){return 0;}
        int left = 1; //this denotes the min value 
        int right = *max_element(quantities.begin(), quantities.end());
        
        while(left < right){
            int mid = left + (right - left) / 2;
            
            if(canDistribute(n, quantities, mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left; // return the min value
    }

    bool canDistribute(int n, vector<int> &quantities, int max){
        // if(max == 0){
        //     return false;
        // }
        int store = 0;

        for(int arr : quantities){
            store += (arr + max - 1) / max;

            if(store > n){
                //the number of stores is greater, hence not feasible
                return false;
            }
        }
        return true;
    }
};