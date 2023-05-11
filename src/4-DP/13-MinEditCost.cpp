#include"headFile.h"

// 最小编辑代价
class MinEditCost {
public:

    int minCost(string s1, string s2, int ic, int dc, int rc) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1));
        for (int j = 0; j <= m; j++) {
            dp[0][j] = ic * j;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = dc * i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + rc;
                }
                dp[i][j] = min(dp[i][j - 1] + ic, dp[i - 1][j] + dc);
            }
        }
        return dp[n][m];
    }

};