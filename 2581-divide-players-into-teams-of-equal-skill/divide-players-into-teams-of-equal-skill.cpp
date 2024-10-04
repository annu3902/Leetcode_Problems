class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;

        int n = skill.size();
        if(n & 1 != 0) return -1;

        sort(begin(skill), end(skill));
        int low = 0;
        int high = n-1;
        int temp = skill[high] + skill[low];

        while(low <= high){
            int sum = skill[high]+skill[low];
            if(sum != temp) return -1;
            long long product = skill[high]*skill[low];
            ans += product;
            high--;
            low++;
        }

        return ans;
    }
};