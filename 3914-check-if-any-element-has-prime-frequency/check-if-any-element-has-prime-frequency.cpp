class Solution {
public:
    bool checkPrime(int n, vector<int> & vec){
        if(n == 1) return false;
        else if(n == 2) return true;

        else if(vec[n] == 0) return false;
        return true;

    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        vector<int> vec(101, 1);

        for(int i=2; i<=100; i++){
            for(int j=2; j<=50; j++){
                if(i*j <= 100)
                vec[i*j] = 0;
                
                else break;
            }
        }

        for(auto it : mp){
            if(checkPrime(it.second, vec)) return true;
        }

        return false;
    }
};