#include"headFile.h"

class NumsOfDesiredExpression {
public:

    // express: "1^0|0&1"
    // desired: true/false

    int nums1(string express, bool desired) {
        if (express == "") {
            return 0;
        }
        if (!isValid(express)) {
            return 0;
        }
        return p(express, desired, 0, express.size() - 1);
    }

    bool isValid(string str) {
        if ((str.size() & 1) == 0) {
            return false;
        }
        for (int i = 0; i < str.size(); i += 2) {
            if (str[i] != '0' && str[i] != '1') {
                return false;
            }
        }
        for (int i = 1; i < str.size(); i += 2) {
            if (str[i] != '&' && str[i] != '|' && str[i] != '^') {
                return false;
            }
        }
        return true;
    }

    // L和R一定是偶数，对应的字符一定是0或1
    int p(string s, bool desired, int L, int R) {
        if (L == R) {
            if (s[L] == '1') {
                return desired ? 1 : 0;
            } else {
                return desired ? 0 : 1;
            }
        }

        int ans = 0;
        if (desired) {
            // i位置一定是&,|,^
            for (int i = L + 1; i < R; i += 2) {
                switch (s[i]) {
                case '&':
                    ans += p(s, true, L, i - 1) * p(s, true, i + 1, R);
                    break;
                case '|':
                    ans += p(s, true, L, i - 1) * p(s, true, i + 1, R);
                    ans += p(s, true, L, i - 1) * p(s, false, i + 1, R);
                    ans += p(s, false, L, i - 1) * p(s, true, i + 1, R);
                    break;
                case '^':
                    ans += p(s, true, L, i - 1) * p(s, false, i + 1, R);
                    ans += p(s, false, L, i - 1) * p(s, true, i + 1, R);
                    break;
                }
            }
        } else {
            for (int i = L + 1; i < R; i += 2) {
                switch (s[i]) {
                case '&':
                    ans += p(s, false, L, i - 1) * p(s, false, i + 1, R);
                    ans += p(s, false, L, i - 1) * p(s, true, i + 1, R);
                    ans += p(s, true, L, i - 1) * p(s, false, i + 1, R);
                    break;
                case '|':
                    ans += p(s, false, L, i - 1) * p(s, false, i + 1, R);
                    break;
                case '^':
                    ans += p(s, true, L, i - 1) * p(s, true, i + 1, R);
                    ans += p(s, false, L, i - 1) * p(s, false, i + 1, R);
                    break;
                }
            }
        }
        return ans;
    }


    int nums2(string express, bool desired) {
        if (express == "") {
            return 0;
        }
        if (!isValid(express)) {
            return 0;
        }
        int n = express.size();
        vector<vector<int>>tmp(n, vector<int>(2));
        vector<vector<vector<int>>>dp(n, tmp);
        for (int i = 0; i < n; i += 2) {
            if (express[i] == '1') {
                dp[i][i][0] = 0;
                dp[i][i][1] = 1;
            } else {
                dp[i][i][0] = 1;
                dp[i][i][1] = 0;
            }
        }

        for (int L = n - 3; L >= 0; L -= 2) {
            for (int R = L; R < n; R += 2) {
                // i位置一定是&,|,^
                int trueAns = 0;
                int falseAns = 0;
                for (int i = L + 1; i < R; i += 2) {
                    switch (express[i]) {
                    case '&':
                        trueAns += dp[L][i - 1][1] * dp[i + 1][R][1];
                        falseAns += dp[L][i - 1][0] * dp[i + 1][R][0]
                            + dp[L][i - 1][1] * dp[i + 1][R][0]
                            + dp[L][i - 1][0] * dp[i + 1][R][1];
                        break;
                    case '|':
                        trueAns += dp[L][i - 1][1] * dp[i + 1][R][1]
                            + dp[L][i - 1][1] * dp[i + 1][R][0]
                            + dp[L][i - 1][0] * dp[i + 1][R][1];
                        falseAns += dp[L][i - 1][0] * dp[i + 1][R][0];
                        break;
                    case '^':
                        trueAns += dp[L][i - 1][1] * dp[i + 1][R][0]
                            + dp[L][i - 1][0] * dp[i + 1][R][1];
                        falseAns += dp[L][i - 1][0] * dp[i + 1][R][0]
                            + dp[L][i - 1][1] * dp[i + 1][R][1];
                        break;
                    }
                }
                dp[L][R][0] = falseAns;
                dp[L][R][1] = trueAns;
            }
        }
        return dp[0][n - 1][desired ? 1 : 0];
    }


};