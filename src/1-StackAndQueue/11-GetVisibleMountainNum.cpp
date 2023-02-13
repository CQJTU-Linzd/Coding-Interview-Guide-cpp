#include"headFile.h"

// �ɼ���ɽ�������
class GetVisibleNum {
public:
    // ���ظ�ֵ
    int getNumNoRepeat(vector<int>& nums) {
        return 2 * (nums.size() - 2) + 1;
    }

    // �������ظ�ֵ
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
        stack<Record>stack; // ��ջ����ջ�ף�value���Ե���
        // �����ֵ��¼�Ž�ȥ
        stack.push(Record(nums[maxIndex], 1));
        // �����ֵλ�õ���һ��λ�ÿ�ʼ����next�����������ʱ�룩
        int index = nextIndex(maxIndex, nums.size());
        int res = 0;
        while (index != maxIndex) {
            while (stack.top().value < nums[index]) {
                Record popRecord = stack.top();
                stack.pop();
                int K = popRecord.times;
                res += 2 * K + getInternalSum(K);
            }
            // ��ǰԪ����ջ�����ջ��Ԫ�غ�����ͬ���ͺϲ�
            if (stack.top().value == nums[index]) {
                stack.top().times++;
            } else {
                stack.push(Record(nums[index], 1));
            }
            index = nextIndex(index, nums.size());
        }
        // ����׶�
        // ��һС�׶�
        while (stack.size() > 2) {
            int K = stack.top().times;
            stack.pop();
            res += 2 * K + getInternalSum(K);
        }
        // �ڶ�С�׶�
        if (stack.size() == 2) {
            int K = stack.top().times;
            stack.pop();
            res += getInternalSum(K) + (stack.top().times == 1 ? K : 2 * K);
        }
        // ����С�׶�
        res += getInternalSum(stack.top().times);
        return res;
    }

    int nextIndex(int i, int size) {
        return i + 1 == size ? 0 : i + 1;
    }

    // k==1������0��k>1������C(2, k)
    int getInternalSum(int k) {
        return k == 1 ? 0 : (k * (k - 1) / 2);
    }
};