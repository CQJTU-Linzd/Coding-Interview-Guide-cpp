#include"headFile.h"

// 和为k的二元组统计（需要去重）
class UniquePairsOfSumK {
public:

    // 暴力

    vector<vector<int>> getUniquePairs1(vector<int>& arr, int k) {
        if (arr.empty()) {
            return vector<vector<int>>{};
        }
        sort(arr.begin(), arr.end());
        vector<vector<int>>res;
        unordered_set<string>set;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] + arr[j] == k) {
                    string cur = to_string(arr[i]) + "_" + to_string(arr[j]);
                    if (set.count(cur)) {
                        continue;
                    }
                    res.push_back(vector<int>{arr[i], arr[j]});
                    set.insert(cur);
                }
            }
        }
        return res;
    }

    // 正式

    vector<vector<int>> getUniquePairs2(vector<int>& arr, int k) {
        if (arr.empty()) {
            return vector<vector<int>>{};
        }
        sort(arr.begin(), arr.end());
        vector<vector<int>>res;
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            if (arr[left] + arr[right] == k) {
                if (left == 0 || arr[left] != arr[left - 1]) {
                    res.push_back(vector<int>{arr[left], arr[right]});
                }
                left++;
                right--;
            } else if (arr[left] + arr[right] < k) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }


    // for test


    // 生成大小为size，数据范围在l~r的随机数组
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
        for (int t = 0; t < 1000; t++) {
            int size = rand() % (1000 - 1 + 1) + 1;
            int k = rand() % (100 - (-100) + 1) - 100;
            auto arr = randomArray(size, -100, 100);

            auto ans1 = getUniquePairs1(arr, k);
            auto ans2 = getUniquePairs2(arr, k);

            sort(ans1.begin(), ans1.end(), [](vector<int>& a, vector<int>& b)->int {
                return a[0] < b[0];
                 });
            sort(ans2.begin(), ans2.end(), [](vector<int>& a, vector<int>& b)->int {
                return a[0] < b[0];
                 });

            if (ans1 != ans2) {
                cout << "fuck" << endl;
            }
        }
    }

};

//int main() {
//    UniquePairsOfSumK ups;
//    ups.test();
//
//    return 0;
//}