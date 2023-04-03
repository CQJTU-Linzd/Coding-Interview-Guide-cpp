#include"headFile.h"

// 每种硬币无限次
// 换钱的最少硬币数
class MinCoins {
public:
    // 暴力递归
    int minCoins1(vector<int>& arr, int aim) {
        return process(arr, 0, aim);
    }
    int process(vector<int>& arr, int i, int rest) {
        if (i == arr.size()) {
            return rest == 0 ? 0 : -1;
        }
        int res = -1;
        for (int k = 0; k * arr[i] <= rest; k++) {
            int next = process(arr, i + 1, rest - k * arr[i]); // 后续的硬币数
            if (next != -1) {
                res = res == -1 ? k + next : min(res, k + next);
            }
        }
        return res;
    }

    // dp
    int minCoins2(vector<int>& arr, int aim) {
        int n = arr.size();
        vector<vector<int>>dp(n + 1, vector<int>(aim + 1));
        for (int rest = 0; rest <= aim; rest++) {
            dp[n][rest] = rest == 0 ? 0 : -1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int rest = 0; rest <= aim; rest++) {
                dp[i][rest] = -1;
                if (dp[i + 1][rest] != -1) {
                    dp[i][rest] = dp[i + 1][rest];
                }
                if (rest - arr[i] >= 0 && dp[i][rest - arr[i]] != -1) {
                    dp[i][rest] = dp[i][rest] == -1 ? dp[i][rest - arr[i]] + 1 : min(dp[i][rest], dp[i][rest - arr[i]] + 1);
                }
            }
        }
        return dp[0][aim];
    }
    // 状态压缩
    int minCoins3(vector<int>& arr, int aim) {
        int n = arr.size();
        vector<int>dp(aim + 1);
        dp[0] = 0;
        for (int rest = 1; rest <= aim; rest++) {
            dp[rest] = -1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int rest = 0; rest <= aim; rest++) {
                if (rest - arr[i] >= 0 && dp[rest - arr[i]] != -1) {
                    dp[rest] = dp[rest] == -1 ? dp[rest - arr[i]] + 1 : min(dp[rest], dp[rest - arr[i]] + 1);
                }
            }
        }
        return dp[aim];
    }

    // for test

    // 生成大小为size，数据范围在l~r的随机数组
    vector<int> randomArray(int size, int l, int r) {
        srand(time(0));
        vector<int>nums;
        set<int>st;
        for (int i = 0; i < size; i++) {
            int num = rand() % (r - l + 1) + l;
            if (!st.count(num)) {
                nums.push_back(num);
                st.insert(num);
            }
        }
        return nums;
    }

    void test() {
        for (int test = 0; test < 10000; test++) {
            int size = rand() % (100 - 1 + 1) + 1;
            vector<int>arr = randomArray(size, 0, 1000);
            int aim = rand() % (1000 - 1 + 1) + 1;
            int ans1 = minCoins2(arr, aim);
            int ans2 = minCoins3(arr, aim);
            if (ans1 != ans2) {
                cout << "fuck" << endl;
            }
        }
    }
};