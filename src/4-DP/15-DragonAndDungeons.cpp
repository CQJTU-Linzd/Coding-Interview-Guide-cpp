#include"headFile.h"

// 龙与地下城游戏
class DragonAndDungeons {
public:

    int minHp(vector<vector<int>>& map) {
        if (map.empty() || map[0].empty()) {
            return 1;
        }
        int n = map.size();
        int m = map[0].size();
        vector<vector<int>>dp(n, vector<int>(m));
        dp[n - 1][m - 1] = map[n - 1][m - 1] > 0 ? 1 : -map[n - 1][m - 1] + 1;
        for (int j = m - 2; j >= 0; j--) {
            dp[n - 1][j] = max(1, dp[n - 1][j + 1] - map[n - 1][j]);
        }
        for (int i = n - 2; i >= 0; i--) {
            dp[i][m - 1] = max(1, dp[i + 1][m - 1] - map[i][m - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                int right = max(dp[i][j + 1] - map[i][j], 1);
                int down = max(dp[i + 1][j] - map[i][j], 1);
                dp[i][j] = min(right, down);
            }
        }
        return dp[0][0];
    }

};