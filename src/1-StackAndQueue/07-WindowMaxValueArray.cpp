#include"headFile.h"

// ���ɴ������ֵ����
class MaxValueWindow {
public:
    // ���ڳ���Ϊw���������һ���ÿ������������ֵ��������
    vector<int> getMaxWindow(vector<int>& nums, int w) {
        vector<int>ans(nums.size() - w + 1);
        deque<int>qmax;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!qmax.empty() && nums[qmax.back()] <= nums[i]) {
                qmax.pop_back();
            }
            qmax.push_back(i);
            if (qmax.front() <= i - w) {
                qmax.pop_front();
            }
            if (i >= w - 1) {
                ans[index++] = nums[qmax.front()];
            }
        }
        return ans;
    }

    // for test
    // ������
    vector<int> getMaxWindow2(vector<int>& nums, int w) {
        vector<int>ans(nums.size() - w + 1);
        for (int i = 0; i < ans.size(); i++) {
            int cur = nums[i];
            for (int j = i; j < i + w; j++) {
                cur = max(cur, nums[j]);
            }
            ans[i] = cur;
        }
        return ans;
    }


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
        for (int test = 0; test < 100000; test++) {
            int size = rand() % (10000 - 1 + 1) + 1;
            int k = rand() % (size - 1 + 1) + 1;
            vector<int>nums = randomArray(size, 0, 1000);
            vector<int>ans1 = getMaxWindow2(nums, k);
            vector<int>ans2 = getMaxWindow(nums, k);
            if (ans1 != ans2) {
                cout << "fuck!!!" << endl;
                break;
            }
        }
        cout << "end" << endl;
    }
};