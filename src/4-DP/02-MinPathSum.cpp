#include"headFile.h"

// 矩阵最小路径和
class MinPathSum {
public:
    int minPathSum(vector<vector<int>>& path) {
        int n = path.size();
        int m = path[0].size();
        vector<vector<int>>dp(n, vector<int>(m));
        dp[0][0] = path[0][0];
        for (int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j - 1] + path[0][j];
        }
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + path[i][0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + path[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }

    // 状态压缩
    int minPathSum2(vector<vector<int>>& path) {
        int n = path.size();
        int m = path[0].size();
        int more = n >= m ? n : m;
        int less = more == n ? m : n;
        bool rowMore = more == n;
        vector<int>dp(less);
        dp[0] = path[0][0];
        for (int i = 1; i < less; i++) {
            dp[i] = dp[i - 1] + rowMore ? path[0][i - 1] : path[i - 1][0];
        }
        for (int i = 1; i < more; i++) {
            dp[0] = dp[0] + rowMore ? path[i - 1][0] : path[0][i - 1];
            for (int j = 1; j < less; j++) {
                dp[j] = min(dp[j - 1], dp[j]) + rowMore ? path[i][j] : path[j][i];
            }
        }
        return dp[less - 1];
    }
};