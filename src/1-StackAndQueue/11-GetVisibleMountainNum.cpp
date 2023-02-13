#include"headFile.h"

// 可见的山峰对数量
class GetVisibleNum {
public:
    // 无重复值
    int getNumNoRepeat(vector<int>& nums) {
        return 2 * (nums.size() - 2) + 1;
    }

    // 可能有重复值
    class Record {
    public:
        int value;
        int times;
        Record(int val, int time) {
            this->value = val;
            this->times = time;
        }
    };

    int getNum(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxIndex = nums[i] > nums[maxIndex] ? i : maxIndex;
        }
        stack<Record>stack; // 从栈顶到栈底，value属性递增
        // 把最大值记录放进去
        stack.push(Record(nums[maxIndex], 1));
        // 从最大值位置的下一个位置开始，沿next方向遍历（逆时针）
        int index = nextIndex(maxIndex, nums.size());
        int res = 0;
        while (index != maxIndex) {
            while (stack.top().value < nums[index]) {
                Record popRecord = stack.top();
                stack.pop();
                int K = popRecord.times;
                res += 2 * K + getInternalSum(K);
            }
            // 当前元素入栈，如果栈底元素和它相同，就合并
            if (stack.top().value == nums[index]) {
                stack.top().times++;
            } else {
                stack.push(Record(nums[index], 1));
            }
            index = nextIndex(index, nums.size());
        }
        // 清算阶段
        // 第一小阶段
        while (stack.size() > 2) {
            int K = stack.top().times;
            stack.pop();
            res += 2 * K + getInternalSum(K);
        }
        // 第二小阶段
        if (stack.size() == 2) {
            int K = stack.top().times;
            stack.pop();
            res += getInternalSum(K) + (stack.top().times == 1 ? K : 2 * K);
        }
        // 第三小阶段
        res += getInternalSum(stack.top().times);
        return res;
    }

    int nextIndex(int i, int size) {
        return i + 1 == size ? 0 : i + 1;
    }

    // k==1，返回0；k>1，返回C(2, k)
    int getInternalSum(int k) {
        return k == 1 ? 0 : (k * (k - 1) / 2);
    }
};