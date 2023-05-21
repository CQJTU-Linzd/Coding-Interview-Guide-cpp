#include"headFile.h"

class CardGame {
public:

    int whoWin1(vector<int>& arr) {
        return process(arr, 0, 0, arr.size() - 1);
    }

    // cur == 0 œ» ÷
    int process(vector<int>& arr, int cur, int L, int R) {
        if (L == R) {
            return cur == 0 ? arr[L] : 0;
        }
        if (cur == 0) {
            return max(
                arr[L] + process(arr, 1, L + 1, R),
                arr[R] + process(arr, 1, L, R - 1)
            );
        } else {
            return min(
                process(arr, 0, L + 1, R),
                process(arr, 0, L, R - 1)
            );
        }
    }


    int whoWin2(vector<int>& arr) {
        return f(arr, 0, arr.size() - 1);
    }

    int f(vector<int>& arr, int L, int R) {
        if (L == R) {
            return arr[L];
        }
        return max(arr[L] + s(arr, L + 1, R), arr[R] + s(arr, L, R - 1));
    }

    int s(vector<int>& arr, int L, int R) {
        if (L == R) {
            return 0;
        }
        return min(f(arr, L + 1, R), f(arr, L, R - 1));
    }


    // dp
    int whoWin3(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>tmp(n, vector<int>(2));
        vector<vector<vector<int>>>dp(n, tmp);
        for (int i = 0; i < n; i++) {
            dp[i][i][0] = arr[i];
        }
        for (int L = n - 2; L >= 0; L--) {
            for (int R = L + 1; R < n; R++) {
                dp[L][R][0] = max(arr[L] + dp[L + 1][R][1], arr[R] + dp[L][R - 1][1]);
                dp[L][R][1] = min(dp[L + 1][R][0], dp[L][R - 1][0]);
            }
        }
        return dp[0][n - 1][0];
    }



    // for test

    vector<int> randomArray(int size, int l, int r) {
        srand(time(0));
        vector<int>nums;
        for (int i = 0; i < size; i++) {
            nums.push_back(rand() % (r - l + 1) + l);
        }
        return nums;
    }

    void test() {
        srand(time(0));
        /*for (int t = 0; t < 5000; t++) {
            int size = rand() % (20 - 1 + 1) + 1;
            vector<int>arr = randomArray(size, 1, 100);
            int ans1 = whoWin1(arr);
            int ans2 = whoWin2(arr);
            if (ans1 != ans2) {
                cout << "fuck" << endl;
            }
        }*/

        for (int t = 0; t < 500; t++) {
            int size = rand() % (30 - 1 + 1) + 1;
            vector<int>arr = randomArray(size, 1, 100);
            int ans1 = whoWin1(arr);
            int ans2 = whoWin3(arr);
            if (ans1 != ans2) {
                cout << "fuck" << endl;
            }
        }

    }

};

//int main() {
//    CardGame cg;
//    cg.test();
//    return 0;
//}