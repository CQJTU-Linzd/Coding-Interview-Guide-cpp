#include"headFile.h"

// �鲢����
// �ݹ� ����ź��� �ұ��ź��� ʹ����������
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
        while (p1 <= M && p2 <= R) { // ����Խ��
            // nums[p1]��С p1�����ƶ� nums[p2]��С p2�����ƶ�
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

// ������������
// ����һ�������һ����num ��������С��num��ֵ����� ����num��ֵ���м� ����num��ֵ���ұ�
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

// ��������3.0
class QuickSort {
public:
    void quickSort(vector<int>& nums, int L, int R) {
        if (L < R) {
            int randIndex = L + (int)(rand() * (R - L + 1));
            swap(nums[randIndex], nums[R]);
            vector<int>p = partition(nums, L, R); // ��СΪ2 ��¼ ����ֵ���� ����߽���ұ߽�
            quickSort(nums, L, p[0] - 1); // <��
            quickSort(nums, p[1] + 1, R); // >��
        }
    }
    vector<int> partition(vector<int>& nums, int L, int R) {
        int less = L - 1; // <���ұ߽�
        int more = R; // >����߽�
        // nums[R]������ֵ
        while (L < more) { // L�ǵ�ǰ����λ��
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


// ������ ����� С����
// �����ź�������飺�����ź����ÿ��Ԫ���ƶ��ľ��벻����k
class sortedDistanceLessK {
public:
    void sortedDistanceLessk(vector<int>& nums, int k) {
        // Ĭ��С����
        priority_queue<int, vector<int>>heap;
        int index = 0;
        // ��ǰk�����Ž�С����
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


// Ͱ���� �����ڱȽϵ�����
// �������� 
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

// ��������
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
        for (int d = 1; d <= digit; d++) { // �ж���λ�ͽ�������
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