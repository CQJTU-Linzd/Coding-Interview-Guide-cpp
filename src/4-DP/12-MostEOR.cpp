#include"headFile.h"

// 子数组异或和为0的最多划分
class MostEOR {
public:

    int mostEOR(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        int eor = 0;
        vector<int>dp(arr.size());
        unordered_map<int, int>map;
        map[0] = -1;
        dp[0] = arr[0] == 0 ? 1 : 0;
        map[arr[0]] = 0;
        for (int i = 1; i < arr.size(); i++) {
            eor ^= arr[i];
            if (map.count(eor)) {
                int preEorIndex = map[eor];
                // 如果preEorIndex == -1, 说明当前的i是第一个满足：arr[0...i]的异或和=0
                dp[i] = preEorIndex == -1 ? 1 : (dp[preEorIndex] + 1);
            }
            dp[i] = max(dp[i - 1], dp[i]);
            map[eor] = i;
        }
    }

};