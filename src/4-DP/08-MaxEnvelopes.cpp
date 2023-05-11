#include"headFile.h"

// 信封嵌套问题
class MaxEnvelopes {
public:
    class Cmp {
    public:
        // 按照长从小到大排，长度一样，按宽从大到小排
        bool operator()(vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                return a[1] > b[1];
            }
        }
    };

    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), Cmp());
        // 对数组的宽求最长递增子序列
        vector<int>ends(arr.size());
        int right = 0;
        ends[0] = arr[0][1];
        for (int i = 1; i < arr.size(); i++) {
            int l = 0;
            int r = right;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (ends[m] >= arr[i][1]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            right = max(right, l);
            ends[l] = arr[i][1];
        }
        return right + 1;
    }
};