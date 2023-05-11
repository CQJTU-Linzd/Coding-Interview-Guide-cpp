#include"headFile.h"

// 字符串的交错组成
class StringIsCross {
public:

    bool isCross(string s1, string s2, string aim) {
        if (s1.size() + s2.size() != aim.size()) {
            return false;
        }
        int n = s1.size();
        int m = s2.size();
        vector<vector<bool>>dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) {
            if (s2[j - 1] != aim[j - 1]) {
                break;
            }
            dp[0][j] = true;
        }
        for (int i = 1; i <= n; i++) {
            if (s1[i - 1] != aim[i - 1]) {
                break;
            }
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == aim[i + j - 1] && dp[i - 1][j]
                    || s2[j - 1] == aim[i + j - 1] && dp[i][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[n][m];
    }

};