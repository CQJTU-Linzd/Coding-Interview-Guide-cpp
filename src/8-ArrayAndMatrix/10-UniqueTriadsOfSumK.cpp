#include"headFile.h"

// 和为k的三元组统计（需要去重）
class UniqueTriadsOfSumK {
public:

    // 暴力

    vector<vector<int>> getUniqueTriad1(vector<int>& arr, int k) {
        if (arr.empty()) {
            return vector<vector<int>>{};
        }
        sort(arr.begin(), arr.end());
        vector<vector<int>>res;
        unordered_set<string>set;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                for (int m = j + 1; m < arr.size(); m++) {
                    if (arr[i] + arr[j] + arr[m] == k) {
                        string cur = to_string(arr[i]) + "_" + to_string(arr[j]) + "_" + to_string(arr[m]);
                        if (set.count(cur)) {
                            continue;
                        }
                        res.push_back(vector<int>{arr[i], arr[j], arr[m]});
                        set.insert(cur);
                    }
                }
            }
        }
        return res;
    }


    // 正式

    vector<vector<int>> getUniqueTriad2(vector<int>& arr, int k) {
        if (arr.empty() || arr.size() < 3) {
            return vector<vector<int>>{};
        }
        sort(arr.begin(), arr.end());
        vector<vector<int>>res;

        for (int i = 0; i < arr.size() - 2; i++) {
            if (i == 0 || arr[i] != arr[i - 1]) {
                int l = i + 1;
                int r = arr.size() - 1;
                int aim = k - arr[i];
                // 在l...r范围上，找到所有和为aim的二元组
                while (l < r) {
                    if (arr[l] + arr[r] > aim) {
                        r--;
                    } else if (arr[l] + arr[r] < aim) {
                        l++;
                    } else {
                        if (l == i + 1 || arr[l] != arr[l - 1]) {
                            res.push_back(vector<int>{arr[i], arr[l], arr[r]});
                        }
                        l++;
                        r--;
                    }
                }
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
            int size = rand() % (200 - 1 + 1) + 1;
            int k = rand() % (100 - (-100) + 1) - 100;
            auto arr = randomArray(size, -100, 100);

            auto ans1 = getUniqueTriad1(arr, k);
            auto ans2 = getUniqueTriad2(arr, k);

            sort(ans1.begin(), ans1.end(), [](vector<int>& a, vector<int>& b)->int {
                return a[0] != b[0] ? a[0] < b[0] : (a[1] < b[1]);
                 });
            sort(ans2.begin(), ans2.end(), [](vector<int>& a, vector<int>& b)->int {
                return a[0] != b[0] ? a[0] < b[0] : (a[1] < b[1]);
                 });

            if (ans1 != ans2) {
                cout << "fuck" << endl;
            }

        }
    }

};

//int main() {
//    UniqueTriadsOfSumK uts;
//    uts.test();
//    return 0;
//}