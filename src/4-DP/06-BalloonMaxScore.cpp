#include"headFile.h"

// 打气球的最大分数
class MaxScore {
public:
    int maxScore1(vector<int>& arr) {
        vector<int>help = arr;
        help.insert(help.begin(), 1);
        help.push_back(1);
        return process(help, 1, help.size() - 2);
    }
    // 含义：要打爆arr[L...R]上的气球，最大得分
    // 潜台词：L-1和R+1上的气球还没有被打爆
    int process(vector<int>& arr, int L, int R) {
        if (L == R) {
            return arr[L] * arr[L - 1] * arr[R + 1];
        }
        // 最后打爆L位置的气球
        int p1 = arr[L - 1] * arr[L] * arr[R + 1] + process(arr, L + 1, R);
        // 最后打爆R位置的气球
        int p2 = arr[L - 1] * arr[R] * arr[R + 1] + process(arr, L, R - 1);
        int ans = max(p1, p2);
        // 最后打爆i位置的气球
        for (int i = L + 1; i < R; i++) {
            int cur = arr[i] * arr[L - 1] * arr[R + 1]
                + process(arr, L, i - 1) + process(arr, i + 1, R);
            ans = max(ans, cur);
        }
        return ans;
    }

    // dp
    int maxScore2(vector<int>& arr) {
        int n = arr.size();
        vector<int>help = arr;
        help.insert(help.begin(), 1);
        help.push_back(1);

        vector<vector<int>>dp(n + 2, vector<int>(n + 2));
        for (int i = 1; i <= n; i++) {
            dp[i][i] = help[i] * help[i - 1] * help[i + 1];
        }
        for (int L = n - 1; L >= 1; L--) {
            for (int R = L + 1; R <= n; R++) {
                int p1 = help[L - 1] * help[L] * help[R + 1] + dp[L + 1][R];
                int p2 = help[L - 1] * help[R] * help[R + 1] + dp[L][R - 1];
                dp[L][R] = max(p1, p2);
                for (int i = L + 1; i < R; i++) {
                    int cur = help[i] * help[L - 1] * help[R + 1]
                        + dp[L][i - 1] + dp[i + 1][R];
                    dp[L][R] = max(dp[L][R], cur);
                }
            }
        }
        return dp[1][n];
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
            int n = rand() % (15 - 1 + 1) + 1;
            vector<int>arr = randomArray(n, 1, 100);
            int ans1 = maxScore1(arr);
            int ans2 = maxScore2(arr);
            if (ans1 != ans2) {
                cout << "fuck" << endl;
            }
        }
    }
};