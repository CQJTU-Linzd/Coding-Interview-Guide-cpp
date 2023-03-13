#include"headFile.h"

// ��������������
class MaxBST {
public:

    // ��һ ���ϵ�
    class Info {
    public:
        TreeNode* maxBSTHead;
        int maxBSTSize;
        int min;
        int max;
        Info(TreeNode* h, int size, int mi, int ma) {
            maxBSTHead = h;
            maxBSTSize = size;
            min = mi;
            max = ma;
        }
    };

    TreeNode* getMaxBST1(TreeNode* head) {
        return process(head).maxBSTHead;
    }

    // ������һ��������������������head��������
    // �����Զ���������������������head��������
    // ����������head����������������������ͬ�����������������
    Info process(TreeNode* head) {
        if (head == NULL) {
            return Info(NULL, 0, INT_MAX, INT_MIN);
        }
        Info leftInfo = process(head->left);
        Info rightInfo = process(head->right);
        // ��ȡ��headΪͷ������������Сֵ
        int Min = min({ head->val, leftInfo.min, rightInfo.min });
        // ��ȡ��headΪͷ�������������ֵ
        int Max = max({ head->val, leftInfo.max, rightInfo.max });
        // ֻ���ǿ�����һ����
        int maxSize = max(leftInfo.maxBSTSize, rightInfo.maxBSTSize);
        TreeNode* maxHead = leftInfo.maxBSTSize >= rightInfo.maxBSTSize
            ? leftInfo.maxBSTHead : rightInfo.maxBSTHead;

        // �ж��Ƿ���ڵ����ֿ�����
        if (leftInfo.maxBSTHead == head->left && rightInfo.maxBSTHead == head->right
            && head->val > leftInfo.max && head->val < rightInfo.min) {
            maxSize = leftInfo.maxBSTSize + 1 + rightInfo.maxBSTSize;
            maxHead = head;
        }
        return Info(maxHead, maxSize, Min, Max);
    }


    // ���� �Լ�д��
    class ReturnType {
    public:
        TreeNode* maxBSTHead;
        int maxBSTSize;
        int max;
        int min;
        bool isBST;
        ReturnType(TreeNode* head, int size, int ma, int mi, bool is) {
            maxBSTHead = head;
            maxBSTSize = size;
            max = ma;
            min = mi;
            isBST = is;
        }
    };

    TreeNode* getMaxBST2(TreeNode* head) {
        return f(head).maxBSTHead;
    }

    ReturnType f(TreeNode* head) {
        if (head == NULL) {
            return ReturnType(NULL, 0, INT_MIN, INT_MAX, true);
        }
        ReturnType leftInfo = f(head->left);
        ReturnType rightInfo = f(head->right);
        
        TreeNode* maxHead = NULL;
        int maxSize = 0;
        int Min = INT_MAX;
        int Max = INT_MIN;
        bool isBST = false;

        Min = min({ head->val, leftInfo.min, rightInfo.min });
        Max = max({ head->val, leftInfo.max, rightInfo.max });

        if (leftInfo.isBST && rightInfo.isBST
            && head->val > leftInfo.max && head->val < rightInfo.min) {
            isBST = true;
            maxHead = head;
            maxSize = leftInfo.maxBSTSize + 1 + rightInfo.maxBSTSize;
        } else {
            maxSize = max(leftInfo.maxBSTSize, rightInfo.maxBSTSize);
            maxHead = leftInfo.maxBSTSize >= rightInfo.maxBSTSize
                ? leftInfo.maxBSTHead : rightInfo.maxBSTHead;
        }
        return ReturnType(maxHead, maxSize, Max, Min, isBST);
    }
};