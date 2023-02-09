#include"headFile.h"

// 单调栈结构
// 找某一个位置左边/右边第一个比它小的位置

// 无重复值
class GetNearLessNoRepeat {
public:
    vector<vector<int>> getNearLessNoRepeat(vector<int>& nums) {
        vector<vector<int>>ans(nums.size(), vector<int>(2));
        stack<int>stack; // 从栈顶到栈底递减
        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty() && nums[stack.top()] > nums[i]) {
                int popIndex = stack.top();
                stack.pop();
                int leftNearIndex = stack.empty() ? -1 : stack.top();
                int rightNearIndex = i;
                ans[popIndex][0] = leftNearIndex;
                ans[popIndex][1] = rightNearIndex;
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            int popIndex = stack.top();
            stack.pop();
            int leftNearIndex = stack.empty() ? -1 : stack.top();
            int rightNearIndex = -1;
            ans[popIndex][0] = leftNearIndex;
            ans[popIndex][1] = rightNearIndex;
        }
        return ans;
    }


    // for test
    vector<vector<int>> getNearLessNoRepeat2(vector<int>& nums) {
        vector<vector<int>>ans(nums.size(), vector<int>(2));
        for (int i = 0; i < nums.size(); i++) {
            int leftLessIndex = -1;
            int rightLessIndex = -1;
            
            int cur = i - 1;
            while (cur >= 0) {
                if (nums[cur] < nums[i]) {
                    leftLessIndex = cur;
                    break;
                }
                cur--;
            }

            cur = i + 1;
            while (cur < nums.size()) {
                if (nums[cur] < nums[i]) {
                    rightLessIndex = cur;
                    break;
                }
                cur++;
            }

            ans[i][0] = leftLessIndex;
            ans[i][1] = rightLessIndex;
        }
        return ans;
    }


    vector<int> randomArray(int size, int l, int r) {
        srand(time(0));
        vector<int>nums;
        unordered_set<int>st;
        for (int i = 0; i < size; i++) {
            int num = rand() % (r - l + 1) + l;
            if (!st.count(num)) {
                nums.push_back(num);
                st.insert(num);
            }
        }
        return nums;
    }

    void test() {
        srand(time(0));
        for (int test = 0; test < 100000; test++) {
            int size = rand() % (10000 - 1 + 1) + 1;
            int k = rand() % (size - 1 + 1) + 1;
            vector<int>nums = randomArray(size, 0, 1000);
            vector<vector<int>>ans1 = getNearLessNoRepeat2(nums);
            vector<vector<int>>ans2 = getNearLessNoRepeat(nums);
            if (ans1 != ans2) {
                cout << "fuck!!!" << endl;
                break;
            }
        }
        cout << "end" << endl;
    }
};

// 可能有重复值的单调栈
class GetNearLess {
public:
    vector<vector<int>> getNearLess(vector<int>& nums) {
        vector<vector<int>>res(nums.size(), vector<int>(2));
        stack<vector<int>>stack;
        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty() && nums[stack.top()[0]] > nums[i]) {
                vector<int> popIndexs = stack.top();
                stack.pop();
                int leftLessIndex = stack.empty() ? -1 : stack.top().back();
                for (int popi : popIndexs) {
                    res[popi][0] = leftLessIndex;
                    res[popi][1] = i;
                }
            }
            if (!stack.empty() && nums[stack.top()[0]] == nums[i]) {
                stack.top().push_back(i);
            } else {
                vector<int>list;
                list.push_back(i);
                stack.push(list);
            }
        }
        // 清算
        while (!stack.empty()) {
            vector<int>popIndexs = stack.top();
            stack.pop();
            int leftLessIndex = stack.empty() ? -1 : stack.top().back();
            for (int popi : popIndexs) {
                res[popi][0] = leftLessIndex;
                res[popi][1] = -1;
            }
        }
        return res;
    }

    // for test
    vector<vector<int>> getNearLess2(vector<int>& nums) {
        vector<vector<int>>ans(nums.size(), vector<int>(2));
        for (int i = 0; i < nums.size(); i++) {
            int leftLessIndex = -1;
            int rightLessIndex = -1;

            int cur = i - 1;
            while (cur >= 0) {
                if (nums[cur] < nums[i]) {
                    leftLessIndex = cur;
                    break;
                }
                cur--;
            }

            cur = i + 1;
            while (cur < nums.size()) {
                if (nums[cur] < nums[i]) {
                    rightLessIndex = cur;
                    break;
                }
                cur++;
            }

            ans[i][0] = leftLessIndex;
            ans[i][1] = rightLessIndex;
        }
        return ans;
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
        for (int test = 0; test < 1000; test++) {
            int size = rand() % (1000 - 1 + 1) + 1;
            int k = rand() % (size - 1 + 1) + 1;
            vector<int>nums = randomArray(size, 0, 1000);
            vector<vector<int>>ans1 = getNearLess2(nums);
            vector<vector<int>>ans2 = getNearLess(nums);
            if (ans1 != ans2) {
                cout << "fuck!!!" << endl;
                break;
            }
        }
        cout << "end" << endl;
    }
};
