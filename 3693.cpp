#include <bits/stdc++.h>

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
    vector<int> dp(n+1, INT_MAX);

    dp[0] = 0;

    for(int i = 1; i <=n; i++) {
        int st = max(0,i-3);
        for(int j = st; j < i; j++) {
            if(dp[j] == INT_MAX) continue;

            long long int jump = i - j;
            long long int cost = dp[j] + costs[i - 1] + (jump * jump);

            dp[i] = min<long long int>(dp[i], cost);
        }
    }

    return dp[n];
    }
};

/*
  사람들은 분기예측을 해서 풀더라거요 1, 2, 3일때 빠른 예측을 위해 사용하는 것 같습니다.
  class Solution {
    public:
        int climbStairs(int n, vector<int>& cost) {
    
            vector<int> dp(n + 1, INT_MAX / 2);
    
            dp[0] = 0;
    
            for(int i = 1; i <= n; i++) {
    
                dp[i] = min(dp[i],
                            dp[i - 1] + cost[i - 1] + 1);
    
                if(i >= 2) {
                    dp[i] = min(dp[i],
                                dp[i - 2] + cost[i - 1] + 4);
                }
    
                if(i >= 3) {
                    dp[i] = min(dp[i],
                                dp[i - 3] + cost[i - 1] + 9);
                }
            }
    
            return dp[n];
        }
    };
*/
