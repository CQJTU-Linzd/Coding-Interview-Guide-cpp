#include"headFile.h"

class NumsOfNumberToCharacter {
public:

    int nums1(string str) {
        if (str == "") {
            return 0;
        }
        return process(str, 0);
    }

    int process(string str, int i) {
        if (i == str.size()) {
            return 1;
        }
        int ans = 0;
        if (str[i] == '0') {
            return 0;
        }
        // i位置单独分割
        ans += process(str, i + 1);
        // i和i+1合并
        if (i + 1 < str.size() && (str[i] - '0') * 10 + (str[i + 1] - '0') <= 26) {
            ans += process(str, i + 2);
        }
        return ans;
    }


    int nums2(string str) {
        if (str == "") {
            return 0;
        }
        int n = str.size();
        vector<int>dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] += dp[i + 1];
                if (i + 1 < str.size() && (str[i] - '0') * 10 + (str[i + 1] - '0') <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }

};