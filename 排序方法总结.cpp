#include"headFile.h"

// 归并排序
// 递归 左边排好序 右边排好序 使其整体有序
class MergeSort {
public:
    void Merge(vector<int>& nums) {
        process(nums, 0, nums.size() - 1);
    }
    void process(vector<int>& nums, int L, int R) {
        if (L == R) return;
        int mid = (L + R) / 2;
        process(nums, L, mid);
        process(nums, mid + 1, R);
        merge(nums, L, mid, R);
    }
    void merge(vector<int>& nums, int L, int M, int R) {
        vector<int>help(R - L + 1);
        int i = 0;
        int p1 = 0;
        int p2 = M + 1;
        while (p1 <= M && p2 <= R) { // 都不越界
            // nums[p1]更小 p1往右移动 nums[p2]更小 p2往右移动
            help[i++] = nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++];
        }
        while (p1 <= M) {
            help[i++] = nums[p1++];
        }
        while (p2 <= R) {
            help[i++] = nums[p2++];
        }
        for (int i = 0; i < help.size(); i++) {
            nums[L + i] = help[i];
        }
    }
};

// 荷兰国旗问题
// 给定一个数组和一个数num 把数组中小于num的值放左边 等于num的值放中间 大于num的值放右边
class DutchFlag {
public:
    void process(vector<int>& nums, int num) {
        int less = -1;
        int great = nums.size();
        int i = 0;
        while (i < great) {
            if (nums[i] < num) {
                swap(nums[i], nums[less + 1]);
                less++;
                i++;
            }
            else if (nums[i] == num) {
                i++;
            }
            else {
                swap(nums[i], nums[great - 1]);
                great--;
            }
        }
    }
};

// 快速排序3.0
class QuickSort {
public:
    void quickSort(vector<int>& nums, int L, int R) {
        if (L < R) {
            int randIndex = L + (int)(rand() * (R - L + 1));
            swap(nums[randIndex], nums[R]);
            vector<int>p = partition(nums, L, R); // 大小为2 记录 划分值区域 的左边界和右边界
            quickSort(nums, L, p[0] - 1); // <区
            quickSort(nums, p[1] + 1, R); // >区
        }
    }
    vector<int> partition(vector<int>& nums, int L, int R) {
        int less = L - 1; // <区右边界
        int more = R; // >区左边界
        // nums[R]：划分值
        while (L < more) { // L是当前数的位置
            if (nums[L] < nums[R]) {
                swap(nums[less + 1], nums[L]);
                less++;
                L++;
            }
            else if (nums[L] > nums[R]) {
                swap(nums[L], nums[more - 1]);
                more--;
            }
            else {
                L++;
            }
        }
        swap(nums[R], nums[more]);
        return vector<int>{less + 1, more};
    }
};


// 堆排序 大根堆 小根堆
// 几乎排好序的数组：数组排好序后，每个元素移动的距离不超过k
class sortedDistanceLessK {
public:
    void sortedDistanceLessk(vector<int>& nums, int k) {
        // 默认小根堆
        priority_queue<int, vector<int>>heap;
        int index = 0;
        // 把前k个数放进小根堆
        for (; index <= k; index++) {
            heap.push(nums[index]);
        }
        int i = 0;
        for (; index < nums.size(); i++, index++) {
            heap.push(nums[index]);
            nums[i] = heap.top();
            heap.pop();
        }
        while (!heap.empty()) {
            nums[i++] = heap.top();
            heap.pop();
        }
    }
};


// 桶排序 不基于比较的排序
// 计数排序 
class BucketSort {
public:
    void bucketSort(vector<int>& nums) {
        int maxval = *max_element(nums.begin(), nums.end());
        vector<int>ret(maxval + 1);
        for (int num : nums) {
            ret[num]++;
        }
        for (int i = 0; i < ret.size(); i++) {
            for (int j = 0; j < ret[i]; j++) {
                cout << i << " ";
            }
        }
    }
};

// 基数排序
class RadixSort {
public:
    void radixSort(vector<int>& nums) {
        radixSort(nums, 0, nums.size() - 1, maxbits(nums));
    }
    int maxbits(vector<int>& nums) {
        int maxval = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        if (maxval == 0) return 1;
        while (maxval) {
            cnt++;
            maxval /= 10;
        }
        return cnt;
    }
    void radixSort(vector<int>& nums, int L, int R, int digit) {
        int radix = 10;
        int i = 0, j = 0;
        vector<int>bucket(R - L + 1);
        for (int d = 1; d <= digit; d++) { // 有多少位就进出几次
            vector<int>count(radix);
            for (int i = L; i <= R; i++) {
                j = getDigit(nums[i], d);
                count[j]++;
            }
            for (int i = 1; i < radix; i++) {
                count[i] = count[i - 1] + count[i];
            }
            for (int i = R; i >= L; i--) {
                j = getDigit(nums[i], d);
                bucket[count[j] - 1] = nums[i];
                count[j]--;
            }
            for (int i = L, j = 0; i <= R; i++, j++) {
                nums[i] = count[j];
            }
        }
    }
    int getDigit(int x, int d) {
        return ((x / (int)pow(10, d - 1)) % 10);
    }
};