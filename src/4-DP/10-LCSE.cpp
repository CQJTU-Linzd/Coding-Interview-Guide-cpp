#include"headFile.h"

// 最长公共子序列
class LCSE {
public:
    string lcse(string s1, string s2) {
        if (s1 == "" || s2 == "") {
            return "";
        }
        auto dp = getdp(s1, s2);
        int n = s1.size() - 1;
        int m = s2.size() - 1;
        string res;
        res.resize(dp[n - 1][m - 1]);
        int index = res.size() - 1;
        while (index >= 0) {
            if (m > 0 && dp[n][m] == dp[n][m - 1]) {
                m--;
            } else if (n > 0 && dp[n][m] == dp[n - 1][m]) {
                n--;
            } else {
                res[index--] = s1[n];
                n--;
                m--;
            }
        }
        return res;
    }
    vector<vector<int>> getdp(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp;
    }
};