#include"headFile.h"

// 最长公共子串
class LCST {
public:

    string lcst(string s1, string s2) {
        if (s1 == "" || s2 == "") {
            return "";
        }
        auto dp = getdp(s1, s2);
        // 找dp表中的最大值
        int maxLen = 0;
        int end = 0;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                if (dp[i][j] > maxLen) {
                    end = i;
                    maxLen = dp[i][j];
                }
            }
        }
        return s1.substr(end - maxLen + 1, maxLen);
    }

    vector<vector<int>> getdp(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n, vector<int>(m));
        for (int j = 0; j < m; j++) {
            dp[0][j] = s1[0] == s2[j] ? 1 : 0;
        }
        for (int i = 0; i < n; i++) {
            dp[i][0] = s1[i] == s2[0] ? 1 : 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
        return dp;
    }

};