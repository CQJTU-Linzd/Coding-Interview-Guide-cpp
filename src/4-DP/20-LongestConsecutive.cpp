#include"headFile.h"

// [100, 4, 200, 1, 3, 2]->最长连续序列：[1,2,3,4]，返回4
class LongestConsecutive {
public:

    int maxLength(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        int ans = 1;
        unordered_map<int, int>map;
        for (int i = 0; i < arr.size(); i++) {
            if (!map.count(arr[i])) {
                map[arr[i]] = 1;
                if (map.count(arr[i] - 1)) {
                    ans = max(ans, merge(map, arr[i] - 1, arr[i]));
                }
                if (map.count(arr[i] + 1)) {
                    ans = max(ans, merge(map, arr[i], arr[i] + 1));
                }
            }
        }
        return ans;
    }

    int merge(unordered_map<int, int>& map, int less, int more) {
        int left = less - map[less] + 1;
        int right = more + map[more] - 1;
        int len = right - left + 1;
        map[left] = len;
        map[right] = len;
        return len;
    }

    int maxLength2(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        sort(arr.begin(), arr.end());
        vector<int>dp(arr.size());
        int ans = 1;
        dp[0] = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1] + 1) {
                dp[i] = dp[i - 1] + 1;
            } else if (arr[i] == arr[i - 1]) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = 1;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
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
        for (int t = 0; t < 5000; t++) {
            int size = rand() % (1000 - 1 + 1) + 1;
            vector<int>arr1 = randomArray(size, 1, 1000);
            vector<int>arr2 = arr1;
            int ans1 = maxLength(arr1);
            int ans2 = maxLength2(arr2);
            if (ans1 != ans2) {
                for (int num : arr2) {
                    cout << num << " ";
                }
                cout << endl;
                cout << ans1 << " " << ans2 << endl;
            }
        }

    }

};

int main() {
    LongestConsecutive lc;
    lc.test();
    return 0;
}