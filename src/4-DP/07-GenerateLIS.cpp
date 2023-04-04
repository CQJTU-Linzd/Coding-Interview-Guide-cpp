#include"headFile.h"

// 最长递增子序列
// 需要把子序列生成
class GenerateLIS {
public:
    vector<int> generateLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n);
        vector<int>ends(n);
        ends[0] = arr[0];
        dp[0] = 1;
        int right = 0;
        for (int i = 1; i < arr.size(); i++) {
            int L = 0;
            int R = right;
            while (L <= R) {
                int M = L + (R - L) / 2;
                if (arr[i] > ends[M]) {
                    L = M + 1;
                } else {
                    R = M - 1;
                }
            }
            // L: >=arr[i]最左位置
            right = max(right, L);
            ends[L] = arr[i];
            dp[i] = L + 1;
        }
        return generate(arr, dp);
    }
    vector<int> generate(vector<int>& arr, vector<int>& dp) {
        int len = 0;
        int index = 0;
        auto maxPos = max_element(dp.begin(), dp.end());
        len = *maxPos;
        index = maxPos - dp.begin();
        vector<int>res(len);
        res[--len] = arr[index];
        for (int i = index; i >= 0; i--) {
            if (arr[i] < arr[index] && dp[i] == dp[index] - 1) {
                res[--len] = arr[i];
                index = i;
            }
        }
        return res;
    }
};