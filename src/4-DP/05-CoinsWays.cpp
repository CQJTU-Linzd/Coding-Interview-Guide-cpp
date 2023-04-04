#include"headFile.h"

// 换钱的方法数
class CoinsWays {
public:
    int coinsWays1(vector<int>& arr, int aim) {
        return process(arr, 0, aim);
    }
    int process(vector<int>& arr, int i, int rest) {
        if (i == arr.size()) {
            return rest == 0 ? 1 : 0;
        }
        int ans = 0;
        for (int k = 0; k * arr[i] <= rest; k++) {
            ans += process(arr, i + 1, rest - k * arr[i]);
        }
        return ans;
    }

    // dp
    int coinsWays2(vector<int>& arr, int aim) {
        int n = arr.size();
        vector<vector<int>>dp(n + 1, vector<int>(aim + 1));
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int rest = 0; rest <= aim; rest++) {
                dp[i][rest] = dp[i + 1][rest];
                dp[i][rest] += rest - arr[i] >= 0 ? dp[i][rest - arr[i]] : 0;
            }
        }
        return dp[0][aim];
    }

    // 状态压缩
    int coinsWays3(vector<int>& arr, int aim) {
        int n = arr.size();
        vector<int>dp(aim + 1);
        dp[0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int rest = 0; rest <= aim; rest++) {
                dp[rest] += rest - arr[i] >= 0 ? dp[rest - arr[i]] : 0;
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
        for (int test = 0; test < 1000; test++) {
            int n = rand() % (10 - 1 + 1) + 1;
            vector<int>arr = randomArray(n, 1, 100);
            int aim = rand() % (1000 - 1 + 1) + 1;
            int ans1 = coinsWays1(arr, aim);
            int ans2 = coinsWays2(arr, aim);
            if (ans1 != ans2) {
                cout << "fuck" << endl;
            }
        }
    }
};