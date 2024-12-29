#define ll long long
ll mod = 1000000007;

class Solution {
public:
    ll solve(ll ind1, ll ind2, string &target, ll n, vector<vector<ll>> &dp, vector<vector<ll>> &freq){
        if(ind2 == target.size()){
            return 1;
        }
        if(ind1 == n)return 0;

        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];

        ll ans1 = solve(ind1+1, ind2, target, n, dp, freq);
        ll ans2 = (freq[ind1][target[ind2]-'a'] * solve(ind1+1, ind2+1, target, n, dp, freq))%mod;
        return dp[ind1][ind2] = (ans1 + ans2)%mod;
    }
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = words[0].size();
        int o = target.size();
        vector<vector<ll>> freq(m+1, vector<ll> (26, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                freq[j][words[i][j] - 'a']++;
            }
        }
        vector<vector<ll>> dp(m+1, vector<ll>(o+1, -1));
        return solve(0, 0, target, m, dp, freq);
    }
};