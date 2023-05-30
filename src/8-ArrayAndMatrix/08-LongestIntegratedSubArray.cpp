#include"headFile.h"

class LongestIntegratedSubArray {
public:

    // 暴力 O(n^3)

    int getLIL1(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i; j < arr.size(); j++) {
                if (check(arr, i, j)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }

    bool check(vector<int>& arr, int start, int end) {
        int size = end - start + 1;
        int* tmp = new int[size];
        for (int i = start; i <= end; i++) {
            tmp[i - start] = arr[i];
        }
        sort(tmp, tmp + size);
        for (int i = 1; i < size; i++) {
            if (tmp[i] - tmp[i - 1] != 1) {
                delete[] tmp;
                return false;
            }
        }
        delete[] tmp;
        return true;
    }

    // 正式方法 O(n^2)

    int getLIL2(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        int ans = 0;
        int maxVal = 0;
        int minVal = 0;
        unordered_set<int>set;
        for (int i = 0; i < arr.size(); i++) {
            maxVal = INT_MIN;
            minVal = INT_MAX;
            for (int j = i; j < arr.size(); j++) {
                if (set.count(arr[j])) {
                    break;
                }
                set.insert(arr[j]);
                maxVal = max(maxVal, arr[j]);
                minVal = min(minVal, arr[j]);
                if (maxVal - minVal == j - i) {
                    ans = max(ans, j - i + 1);
                }
            }
            set.clear();
        }
        return ans;
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
        for (int t = 0; t < 500; t++) {
            int size = rand() % (100 - 1 + 1) + 1;
            auto arr = randomArray(size, 1, 20);
            int ans1 = getLIL1(arr);
            int ans2 = getLIL2(arr);
            if (ans1 != ans2) {
                cout << "fuck" << endl;
            }
        }
    }

};

//int main() {
//    LongestIntegratedSubArray lil;
//    lil.test();
//
//    return 0;
//}