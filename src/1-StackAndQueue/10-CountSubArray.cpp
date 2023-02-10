#include"headFile.h"

// 给定数组nums和num，返回nums有多少个子数组满足：
// max(nums[i...j]) - min(nums[i...j]) <= num

class CountSubArray {
public:
    int getNum(vector<int>& nums, int num) {
        if (nums.empty()) {
            return 0;
        }
        deque<int>qmax, qmin;
        int i = 0, j = 0;
        int res = 0;
        while (i < nums.size()) {
            while (j < nums.size()) {
                if (qmin.empty() || qmin.back() != j) { // 防止 i移动之后，j位置又被算一次
                    while (!qmax.empty() && nums[qmax.back()] <= nums[j]) {
                        qmax.pop_back();
                    }
                    qmax.push_back(j);
                    while (!qmin.empty() && nums[qmin.back()] >= nums[j]) {
                        qmin.pop_back();
                    }
                    qmin.push_back(j);
                }
                if (nums[qmax.front()] - nums[qmin.front()] > num) {
                    break;
                }
                j++;
            }
            // 必须以i位置开头的情况下，j向右扩到了最远的位置
            // 则[i...j-1], [i...j-2]...[i...i]都是合法的
            res += j - i;
            if (qmax.front() == i) {
                qmax.pop_front();
            }
            if (qmin.front() == i) {
                qmin.pop_front();
            }
            i++;
        }
        return res;
    }

    // for test

    int getNum2(vector<int>& nums, int num) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int maxVal = nums[i];
                int minVal = nums[i];
                for (int k = i; k <= j; k++) {
                    maxVal = max(maxVal, nums[k]);
                    minVal = min(minVal, nums[k]);
                }
                if (maxVal - minVal <= num) {
                    res++;
                }
            }
        }
        return res;
    }

    vector<int> randomArray(int size, int l, int r) {
        srand(time(0));
        vector<int>nums;
        for (int i = 0; i < size; i++) {
            int num = rand() % (r - l + 1) + l;
            nums.push_back(num);
        }
        return nums;
    }

    void test() {
        srand(time(0));
        for (int test = 0; test < 10000; test++) {
            int size = rand() % (1000 - 1 + 1) + 1;
            vector<int>nums = randomArray(size, 0, 1000);
            int num = rand() % (1000 - 0 + 1) + 0;
            int ans1 = getNum(nums, num);
            int ans2 = getNum2(nums, num);
            if (ans1 != ans2) {
                cout << "fuck!!!" << endl;
            }
        }
        cout << "end" << endl;
    }
};