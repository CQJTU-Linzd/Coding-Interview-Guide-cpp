#include"headFile.h"

// 机器人到达指定位置的方法数
class KStepsWays {
public:
    int ways1(int n, int s, int k, int p) {
        return process(n, p, s, k);
    }
    int process(int n, int p, int cur, int rest) {
        if (rest == 0) {
            return cur == p ? 1 : 0;
        }
        if (cur == 1) {
            return process(n, p, cur + 1, rest - 1);
        } else if (cur == n) {
            return process(n, p, cur - 1, rest - 1);
        } else {
            return process(n, p, cur - 1, rest - 1)
                + process(n, p, cur + 1, rest - 1);
        }
    }

    // dp
    int ways2(int n, int s, int k, int p) {
        vector<vector<int>>dp(k + 1, vector<int>(n + 1));
        for (int cur = 1; cur <= n; cur++) {
            dp[0][cur] = cur == p ? 1 : 0;
        }
        for (int rest = 1; rest <= k; rest++) {
            for (int cur = 1; cur <= n; cur++) {
                if (cur == 1) {
                    dp[rest][cur] = dp[rest - 1][cur + 1];
                } else if (cur == n) {
                    dp[rest][cur] = dp[rest - 1][cur - 1];
                } else {
                    dp[rest][cur] = dp[rest - 1][cur - 1] + dp[rest - 1][cur + 1];
                }
            }
        }
        return dp[k][s];
    }

    // 状态压缩
    int ways3(int n, int s, int k, int p) {
        vector<int>dp(n + 1);
        dp[p] = 1;
        for (int rest = 1; rest <= k; rest++) {
            for (int cur = 1; cur <= n; cur++) {
                if (cur == 1) {
                    dp[cur] = dp[cur + 1];
                } else if (cur == n) {
                    dp[cur] = dp[cur - 1];
                } else {
                    dp[cur] = dp[cur - 1] + dp[cur + 1];
                }
            }
        }
        return dp[s];
    }
};