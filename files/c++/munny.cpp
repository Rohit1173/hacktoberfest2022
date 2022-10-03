class Solution {
public:
    int mod = 1e9 + 7;
    
    int numRollsToTarget(int n, int k, int target) {
        if( target < n || target > k*n  ) return 0;
        vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                for(int x = 1; x <= k; x++){
                    if( x > j ) break;
                    dp[i][j] =(dp[i][j]%mod + dp[i-1][j-x]%mod)%mod;
                }
            }
        }
        return dp[n][target];
    }
};